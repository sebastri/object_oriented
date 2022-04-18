#pragma once
#include "Graph.h"
#include "GUI.h"
using namespace Graph_lib;
class Emoji{
public:
	Emoji(const Emoji&) = delete;
	Emoji& operator=(const Emoji&) = delete;
	Emoji() {}
	virtual void attach_to(Graph_lib::Window&) = 0;
	virtual ~Emoji() {}
};
class linje : public Emoji {
	private:
	Line line;

	public:
	void attach_to(Graph_lib::Window& win){
        line.set_style(Line_style::solid);
        line.set_color(FL_BLUE);
        win.attach(line);
    }
	linje(Point c, Point b):line{c,b}{
        fl_line_style(FL_SOLID);
        fl_color(Color::blue);
        fl_line(c.x,c.y,b.x,b.y, 3, FL_BLACK);
    }
};