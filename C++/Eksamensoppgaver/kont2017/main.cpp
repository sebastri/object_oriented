//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor
#pragma once
#include "std_lib_facilities.h"
#include "array2d.h"

//------------------------------------------------------------------------------'

int main()
{
Array2D v(2,2);
v[0][0] = 4;
v[0][1] = 3;
v[1][0] = 77;
v[1][1] = 81;

cout << v;


keep_window_open();
}

//------------------------------------------------------------------------------
