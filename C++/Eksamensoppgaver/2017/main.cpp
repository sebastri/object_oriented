//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor
#pragma once
#include "std_lib_facilities.h"

#include "Network.h"
//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	/*
	Plant p1("Orkidé", "Stue", 1, 10, 25);
	Plant p2("Kaktus", "Stue", 2, 5, 10);
	Plant p3("Basilikum", "Kjøkken", 3, 25, 50);
	Plant p4("Mynte", "Kjøkken", 4, 20, 50);

	Garden g("Palasset");
	g.addPlant(p1);
	g.addPlant(p2);
	g.addPlant(p3);
	g.addPlant(p4);

	g.monitor(300);
	*/
	//nFac(7);
	//sineTaylor(4,10);

	//testTaylor(4, 0.00000001);
	//testTaylor(114,0.000001);
	/*
	double test= 0;
	int i =0;
	int& gradtall = i;
	for (int i = 0; i < 181; i++)
	{
		if (testTaylor(i,0.000001)>=test)
		{
			test = testTaylor(i,0.000001);
			gradtall = i;
		}
	}
	cout << "gradtall: " << gradtall << " " << test << " ledd";
	*/
	
	Network n;
	vector<string> nodes{};
	n.addPath(nodes);
	
	keep_window_open();
}

//------------------------------------------------------------------------------
