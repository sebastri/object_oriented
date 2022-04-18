#pragma once
#include "GUI.h"

using namespace Graph_lib;

//De forskjellige tilstandene en Tile kan være i
enum class Cell { closed, open, flagged }; 

struct Tile : Button
{
	Tile(Point pos, int size, bool isMine, Graph_lib::Callback cb)
		 :Button(pos, size, size, "", cb), isMine(isMine) {}; 


	void set_label(string s) { label = s; redraw(); }
	void set_label_color(Color c) { pw->labelcolor(c.as_int()); redraw(); }

	// Vis hvor mange miner det er i naborutene
	void setAdjMines(int n);

	void open(); // Åpner ruten
	void reset(); // Resetter ruten
	void flag();// Flagger en rute

	Cell state = Cell::closed;
	bool isMine;
};