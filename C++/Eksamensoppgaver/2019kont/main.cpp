//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "oppg2.h"
//------------------------------------------------------------------------------'


// C++ programs start by executing the function main
int main()
{
	vector<double> x;
	vector<double> y;
	read_csv("csv.txt", x, y);
	
	
	keep_window_open();
}

//------------------------------------------------------------------------------
