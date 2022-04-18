//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor


#include "Graph.h"
#include "Simple_window.h" 

#include <sstream>
#include <string>
#include <vector>
#include <iostream>

void plot_objects(){
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Circle cir{Point{101,101}, 60};
	cir.set_fill_color(Color::red);

	Text text{Point{101,101}, "Kukktryne"};
	text.set_fill_color(Color::blue);
	text.set_font(Font::helvetica);
	text.set_font_size(20);
	text.draw_lines();

	

	win.attach(cir);
	win.attach(text);
	win.wait_for_button();
}

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	plot_objects();

	keep_window_open();
}

//------------------------------------------------------------------------------
