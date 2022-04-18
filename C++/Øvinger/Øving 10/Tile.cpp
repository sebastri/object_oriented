#include "Tile.h"

// For aa sette labelfarge i henhold til hvor mange miner som er rundt
const map<int, Color> minesToColor{ {1, Color::blue},
								   {2, Color::red},
								   {3,Color::dark_green},
								   {4, Color::dark_magenta},
								   {5, Color::dark_blue},
								   {6, Color::dark_cyan},
								   {7, Color::dark_red},
								   {8, Color::dark_yellow} };

// For aa sette Tilelabel i henhold til state
const map<Cell, string> cellToSymbol{ {Cell::closed, ""},
									 {Cell::open, ""},
									 {Cell::flagged, "@<"} };

void Tile::open()
{	
	if(state == Cell::flagged){
	// do nothing
	}
	else if(state != Cell::flagged){
	static_cast<Fl_Button*>(pw)->set();//Setter en button som trykket paa, tilsvarer aapnet rute
	state = Cell::open; //state settes til open

		if (isMine == true){
			set_label("X");
			set_label_color(minesToColor.at(2));
		}
	}
}

void Tile::flag()
{
	if (state == Cell::flagged){
		state = Cell::closed;
		set_label(cellToSymbol.at(Cell::closed));
	}
	else if(state != Cell::flagged){
		state = Cell::flagged;
		set_label(cellToSymbol.at(Cell::flagged));
		set_label_color(minesToColor.at(1));
	}
}

void Tile::setAdjMines(int n){
	set_label(to_string(n));
	set_label_color(minesToColor.at(n));
}

bool Tile::getIsMine() const{
	return isMine;
}
	
void Tile::setIsMine(bool mine){
	isMine = mine;
}
void Tile::reset()
{
	static_cast<Fl_Button*>(pw)->value(0);//Setter en button som ikke trykket p�, tilsvarer lukket rute
	state = Cell::closed;
	set_label(" ");
	isMine = false;
}