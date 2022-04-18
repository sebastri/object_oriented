//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "fil.h"
#include "emnekatalog.h"
#include "temperature1.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	//readToFile();
	//readIn();
	//countCharFile();
	
	/*
	CourseCatalog myobj;
	cout << "Hvor mange fag vil du legge til?: ";
	int x;
	cin >> x;
	for (int i = 0; i < x; i++){
	myobj.addCourse();
	}
	cout << myobj;
	myobj.removeCourse();
	cout << myobj;
	myobj.getCourse();
	*/

	//Oppgave 3c) og d)
	testCatalog();

	//Oppgave 3e)
	/*
	CourseCatalog newobj;
	newobj.loadData("lagring.txt");
	cout << newobj;
	*/

	//Oppgave 4)
	/*
	Temps test;
	test.tempFromFile("temperatures.txt");
	*/
	
	vector<Temps> test = getTempsFromFile("temperatures.txt");


	keep_window_open();
}

//------------------------------------------------------------------------------
