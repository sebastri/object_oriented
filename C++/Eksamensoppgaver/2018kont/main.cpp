//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "observe.h"
//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	Obs b;
	auto b2 = b.openfile("verdier.txt");
	b.report(b2, 1);

	keep_window_open();
}

//------------------------------------------------------------------------------