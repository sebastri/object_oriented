#include "MinesweeperWindow.h"

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines,const string& title):Graph_lib::Window{xy, width * cellSize, height*cellSize, title}, 
width{width}, height{height}, mines{mines}, text{Point{ 200 ,  300}, " " },//Initialiser medlemsvariabler, bruker ogsaa konstruktoren til Windowsklassen
restartAndQuit{Point{200, 350}, 60, 40, Menu::horizontal, "Game End"}
{
	// Legg til alle tiles paa vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int y = i* cellSize,
				x = j * cellSize;
			tiles.push_back(new Tile{ Point{x, y}, cellSize, cb_click,});
			attach(tiles.back());
		}
	}
	restartAndQuit.attach(new Button{Point{0,0},0,0, "Restart", cb_restart});
	restartAndQuit.attach(new Button{Point{0,0},0,0, "Quit", cb_quit});
	attach(restartAndQuit);
	restartAndQuit.hide();
	/*
	tap.set_label("Du tapte");
	tap.set_color(Color::black);
	tap.set_font_size(30);
	attach(tap);
	tap.draw_lines();
	flush();
	*/

	
	while(mines > 0){
		int tilfeldig_tile = rand() % tiles.size();

		if (!tiles[tilfeldig_tile].getIsMine()){
			tiles[tilfeldig_tile].setIsMine(true);
			-- mines;
		}
	}



	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}



int MinesweeperWindow::countMines(vector<Point> points) const {
	int count = 0;
	for (int i = 0; i < points.size(); i++)
	{
		if (at(points[i]).getIsMine())
		{
			count += 1;
		}
		
	}
	return count;
};
vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}
			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

void MinesweeperWindow::openTile(Point xy) {

	if (at(xy).getState()==Cell::closed)
	{
		at(xy).open();
		tellevariabel += 1;
		if (at(xy).getIsMine())
		{
			cout << "Du tapte";
			endgame = false;
			youloose();
			return;
		
		}
		else if (tellevariabel==vunnet)
		{
			cout << "Du vant";
			youwin();
			endgame = true;
			return;
		
		}
		
		if (!at(xy).getIsMine())
		{
			if (countMines(adjacentPoints(xy))>0)
			{
				at(xy).setAdjMines(countMines(adjacentPoints(xy)));
			}
			else
			{
				for (int i = 0; i < adjacentPoints(xy).size(); i++)
				{
					openTile(adjacentPoints(xy)[i]);	
				}
				
			}
			
		}	
	}
}

void MinesweeperWindow::youwin(){
	for (auto i:tiles)
	{
		if (i->getIsMine())
		{
			i->flag();
		}
	}
	text.set_label("Du Vant");
	text.set_color(Color::green);
	text.set_font_size(30);
	attach(text);
	restartAndQuit.show();
	flush();


}
void MinesweeperWindow::youloose(){

	for (auto i:tiles)
	{
		if (i->getIsMine())
		{
			i->open();
		}
	}
		
	text.set_label("Du tapte");
	text.set_color(Color::black);
	text.set_font_size(30);
	attach(text);
	restartAndQuit.show();;
	flush();
	
}




void MinesweeperWindow::flagTile(Point xy) {
	if (at(xy).getState()==Cell::flagged || at(xy).getState()==Cell::closed)
	{
		at(xy).flag();
	}
}


void MinesweeperWindow::restart(){
	for(auto i : tiles){
		i->reset();
	}
	detach(text);
	restartAndQuit.hide();

	Mines = mines;
	while(Mines > 0){
		int tilfeldig_tile = rand() % tiles.size();

		if (!tiles[tilfeldig_tile].getIsMine()){
			tiles[tilfeldig_tile].setIsMine(true);
			-- Mines;
		}
	}

}

//Kaller opentile ved venstreklikk og flagTile ved hoyreklikk/trykke med to fingre paa mac
void MinesweeperWindow::cb_click(Address, Address pw)
{
	Point xy{ Fl::event_x(),Fl::event_y() };
	MouseButton mb = static_cast<MouseButton>(Fl::event_button());
	auto& win = reference_to<MinesweeperWindow>(pw);

	if (!win.inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		win.openTile(xy);
		break;
	case MouseButton::right:
		win.flagTile(xy);
		break;
	}
	win.flush();
	
	


}
