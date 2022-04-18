//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "oppg1.h"
#include "person.h"
#include "templatefunc.h"
//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	/*
	iteratorer1 m;


	vector<string> vec3{"Lorem", "Ipsum", "Dolor", "Lorem"};

	m.task1a();
	m.task1b();
	m.replace(vec3, "Lorem", "Latin");

	//Oppg1d

	cout << "Oppg1d \n";

	set<string> set4{"Lorem", "Ipsum", "Dolor", "Lorem"};

	m.task1d_a();
	m.task1d_b();
	m.replace_set(set4, "Lorem", "Latin");

	//lagrer bare 1 av hvert element, sorterer alfabetisk
	*/

	//Oppgave 2
	list<Person> pers;
	const Person p1{"Sebastian", "Ringdal"};
	const Person p2{"Andreas", "Lie"};
	const Person p3{"Tobias", "Bartfinn"};

	insertOrdered(pers, p1);
	insertOrdered(pers, p2);
	insertOrdered(pers, p3);

	for (auto it = pers.begin(); it != pers.end(); it++)
	{
		cout << *it;
	}
	

	testTemplate();



	cin.get();
}

//------------------------------------------------------------------------------
