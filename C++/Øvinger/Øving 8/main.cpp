//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "Car.h"
#include "Meeting.h"
#include "MeetingWindow.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	system("chcp 65001 > nul");
	Car ferrari{1};
	Person p1{"Bernt", "bernt@hotmail.com",&ferrari};//tar inn peker, må bruke & for å hente adressen ettersom det er en peker, kan fjerne &ferrari og teste om jeg får 0
	Person p2{"Åge", "Åge@hotmail.com"}; 
	Person p3{"Bjarne", "Bjarne@hotmail.com"}; 
	ferrari.reserveFreeSeat();
	cout << p1 << endl;
	
	
	Meeting m{4, 12, 15, Campus::Trondheim, "Corona" , &p1};
	m.addParticipant(&p1);
	m.addParticipant(&p2);
	m.addParticipant(&p3);

	
	cout << m << endl;
	
	MeetingWindow me{Point{0,0}, 400, 400, "test"};
	
	gui_main();
	
	me.printpeople();
	
	keep_window_open();
}

//------------------------------------------------------------------------------
