//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "test.h"

//------------------------------------------------------------------------------'
/*int func(int a, int& b){
	a = 300;
	b = -2;
	return a + b;
}
*/
// C++ programs start by executing the function main
int main()
{
	/*
	int a = 5;
	int b = 10 / a--;
	int c = 10 % (++b);
	cout << a << " " << b << " " << (c += 3);
	*/
	/*
	int i = 0;
	cout << func(i, i) << " ";
	cout << i;
	*/
	/*
	int a = 1;
	{

		int a = 5;
		cout << a;
	}
	cout << a;
	*/
	string s1 = "aaa";
	string s2{"bbb"};
	string s3 = s1 + s2;
	cout << s3 << " " << s3.size() << " ";
	cout << s3[2] << s3[3] << " ";
	s1[1] = 'A' + 2;
	cout << s1 << " " << 'c' - 'a';
	

	keep_window_open();
}

//------------------------------------------------------------------------------
