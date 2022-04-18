//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "minne.h"
#include "Matrix.h"
#include "Dummy.h"


//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	/*
	createFibonacci();
	cout << endl;

	Matrix A;
	cout << A << endl;
	Matrix B(3,4);
	cout << B << endl;
	Matrix C(4);
	cout << C << endl;
	*/
	
	//dummyTest();

	//Oppgave 3b) - 
	//kræsjer fordi objektet peker til samme minnelokasjon, 
	//Prøver derfor å slette 3 ganger det samme minneområdet som pekeren peker på


	Matrix A{2,2};
	A.set(0,0,1.0);
	A.set(0,1,2.0);
	A.set(1,0,3.0);
	A.set(1,1,4.0);

	Matrix B{2,2};
	B.set(0,0,4.0);
	B.set(0,1,3.0);
	B.set(1,0,2.0);
	B.set(1,1,1.0);

	Matrix C{2,2};
	C.set(0,0,1.0);
	C.set(0,1,3.0);
	C.set(1,0,1.5);
	C.set(1,1,2.0);


	cout << (A += B + C);

	
	cin.clear();
	cout << "Please enter a character to exit\n";
	char ch;
	cin >> ch;
	
	
}

//------------------------------------------------------------------------------
