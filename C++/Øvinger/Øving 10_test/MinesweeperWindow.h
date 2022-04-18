#pragma once
#include "Window.h"
#include "Tile.h"

using namespace Graph_lib;
enum class MouseButton { left = FL_LEFT_MOUSE, right = FL_RIGHT_MOUSE }; //

// Minesweeper GUI
class MinesweeperWindow : Graph_lib::Window
{
public:
	//størrelsen til tiles
	static constexpr int cellSize = 30;

	MinesweeperWindow(Point xy, int width, int height, int mines, const string& title);
private:
	
	const int width;//width i miner
	const int height;//heigth i miner
	const int mines;//Antall miner
	int minesLeftUser;//Antall miner spilleren markerer at er igjen
	Vector_ref<Tile> tiles; // Vektor som inneholder alle tiles

	int remainingTiles; //Antall uåpnede tiles som gjenstår før spillet er vunnet
	bool gameIsLost = false; //Hold kontroll på om spillet er tapt
	bool gameIsWon = false; //Hold kontroll på om spillet er vunnet

	//Height og Width i piksler
	int Height() const { return (height + 1) * cellSize; } //+1 pga tekst på toppen
	int Width() const { return width * cellSize; }

	// Få en liste med naborutene rundt en tile
	vector<Point> adjacentPoints(Point xy) const;
	int countMines(vector<Point> coords) const;

	//Sjekk om et punkt er på brettet og gjør om punkt til tile
	bool inRange(Point xy) const { return xy.x >= 0 && xy.x< Width() && xy.y >= cellSize && xy.y < Height(); }
	const Tile& at(Point xy) const { return tiles[xy.x/cellSize + (xy.y/cellSize -1) * width]; }
	Tile& at(Point xy) { return tiles[xy.x / cellSize + (xy.y / cellSize - 1) * width]; }

	void openTile(Point xy);
	void flagTile(Point xy);

	//callback funksjoner for de tre knappene
	static void cb_quit(Address, Address pw) { reference_to<MinesweeperWindow>(pw).hide(); };
	static void cb_restart(Address, Address pw) { reference_to<MinesweeperWindow>(pw).restart(); }
	static void cb_click(Address, Address pw);
	void restart();

	//Funksjoner som kalles når spillet er over
	void gameLost();
	void gameWon();
	void addGameEndMenu(string s, Color c);

	// Medlemsvariabler knyttet til teksten øverst
	Text minesLeftText;
	Rectangle minesLeftBackground;

	//Medlemsvariabler knyttet til spillslutt
	Menu gameEndMenu;
	Rectangle gameEndBackGround;
	Text gameEndText;
};
