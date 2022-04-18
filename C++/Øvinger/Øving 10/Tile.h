#pragma once
#include "GUI.h"

using namespace Graph_lib;

//De forskjellige tilstandene en Tile kan vaere i
enum class Cell { closed, open, flagged };

class Tile : public Button
{
	Cell state = Cell::closed;

	void set_label(string s) { label = s; redraw(); }
	void set_label_color(Color c) { pw->labelcolor(c.as_int()); redraw();}

	bool isMine;
public:
	Tile(Point pos, int size, Graph_lib::Callback cb, bool issMine = false)
		:Button{pos, size, size, "", cb} {
			isMine = issMine;
		};
	
	Cell getState() const {return state; };

	bool getIsMine() const;
	void setIsMine(bool mine);
	void setAdjMines(int n);


	void open(); // aapner ruten
	void flag();// Flagger en rute
	void reset();
};