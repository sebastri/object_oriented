//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"
//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	// printTime(10000);

	/*
	acclY();
	double v = velY(25, 5.0);
	cout << v << endl;
	double f = posX(0, 50, 5.0);
	cout << f << endl;
	double g = posY(0, 25, 5.0);
	cout << g << endl;
	//printTime(sek);
	//flightTime(Ystartfart);
	testDeviation(posX(0.0,50.0,5.0), 250.0, 0.0001, "posX(0.0,50.0,5.0)");
	*/
	//getVelocityVector(60, 60);
	
	//Oppgave 4
	/*
	double velocity = getUserInputAbsVelocity();
	double radianer = degToRad(getUserInputTheta());
	double velx = getVelocityX(radianer, velocity);
	double vely = getVelocityY(radianer, velocity);
	cout << "Skriv inn av stand til målet";
	double distanceToTarget = 0;
	cin >> distanceToTarget;
	double avstandmellom = targetPractice(distanceToTarget, velx, vely);
	*/
	//Oppgave 5

	//a
	/*
	for (int i = 0; i < 3; i++){
    	int tilfeldig = randomWithLimits(0, 100);
    cout << tilfeldig << endl;
    }
	*/
	system("chcp 65001 > nul");
	srand(static_cast<unsigned int>(time(nullptr)));
	playTargetPractise();
	keep_window_open();
}

//------------------------------------------------------------------------------
