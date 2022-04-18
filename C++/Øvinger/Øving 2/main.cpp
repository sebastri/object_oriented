//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor


#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"
#include <iostream>

//------------------------------------------------------------------------------'
void inputAndPrintInteger() {
int x = 0;
cout << "Skriv inn et tall: ";
cin >> x;
cout << "Du skrev: " << x << endl;
}

int inputInteger() {
	cout << "Skriv inn et tall: ";
	int number = 0;
	cin >> number;
	return number;
}

void inputIntegersAndPrintSum(){
int a = inputInteger();
int b = inputInteger();
cout << "Summen av tallene: " << a+b;
}

bool isOdd(int a) {
	if (a % 2 == 0) {
		return false;
	}
	else {
		return true;
	}
}

void printHumanReadableTime(int a) {
	
	int b = a / 3600;
	int c = (a / 60) - b * 60;
	int d = a - (b*3600) - (c*60);
	cout << b << " timer, " << c << " minutt(er) og " << d << " sekunder.";
}

int summere() {
	cout << "Skriv inn så mange tall du vil summere: ";
	int ant = 0;
	int t = 0;
	int x = 0;
	cin >> ant;
	for (int i = 0; i < ant; ++i) {
	cout << "Skriv inn tall: "; 
	cin >> x;
	t = t + x;
	int x = 0;
	}
	cout << t << endl;
	return t;	
}

int summerev2() {
	int x = 1;
	int t = 0;
	cout << "Skriv inn tall som skal multipliseres, skriv '0' for å regne ut " << endl;
	while (x != 0) {
		cout << "skriv inn tall: ";
		cin >> x;
		t = t + x;
	}
	cout << "total sum: " << t << endl;
	return t;
}

double inputDouble() {	
	double number = -1;
	while (number < 0) {
	cout << "Skriv inn et tall: ";
	cin >> number;
	}
	return number;
}

double noktoeuro(){
	cout << "Velkommen til veksling fra NOK til Euro"<<endl;
	double euro = inputDouble();
	euro = euro * 9.75;
	std::cout << std::setprecision(2) << std::fixed;
	std::cout << euro << std::endl;
	return euro;
}

void gangetabell(){
	int b = 0;
	cout << "Skriv inn bredde";
	cin >> b;
	int h = 0;
	cout << "Skriv inn høyde";
	cin >> h;
	for (int i = 1; i <= b; i++) {
		for (int j = 1; j <= h; j++){
		cout << setw(14) << i*j;
		}
		cout << endl;
	}
}

int discriminant(double a, double b, double c) {
	//cout << "Discriminant program (b^2-4ac)"<<endl;
	/*
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	*/
	//cout << ((b*b)-(4*a*c)) << endl;
	return ((b*b)-(4*a*c));
}

void printRealroots(double a, double b, double c) {
	double x1 = 0;
	double x2 = 0;
	double disc = discriminant(a, b, c);
	if (disc > 0){
	x1 = ((-b+sqrt(disc))/2*a);
	x2 = ((-b-sqrt(disc))/2*a);
	cout << "x1 = " << x1 << "x2 = " << x2 << endl;
	}
	else if (disc == 0){
	x1 = -b/2*a;
	cout << "x1 = " << x1 << endl;
	}
	else {
	cout << "Ingen løsninger" << endl;
	}
}

void solveQuadricEquation(){
	cout << "skriv inn tallene a, b og c som beskriver likningen ax^2 + bx + c"<<endl;
	double a = 0;
	double b = 0;
	double c = 0;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	printRealroots(a, b, c);
}

void pythagoras(){
using namespace Graph_lib;
Simple_window win{Point{100,100}, 500, 500, "Pythagoras"};
win.wait_for_button();

Polygon rightTriangle;
rightTriangle.add(Point{300,200});
rightTriangle.add(Point{300,100});
rightTriangle.add(Point{400,200});
rightTriangle.set_fill_color(Color::black);

win.attach(rightTriangle);
win.wait_for_button();

Polygon kvadrat_g;
kvadrat_g.add(Point{300,200});
kvadrat_g.add(Point{200,200});
kvadrat_g.add(Point{200,100});
kvadrat_g.add(Point{300,100});
kvadrat_g.set_fill_color(Color::green);

win.attach(kvadrat_g);
win.wait_for_button();

Polygon kvadrat_b;
kvadrat_b.add(Point{300,100});
kvadrat_b.add(Point{400,0});
kvadrat_b.add(Point{500,100});
kvadrat_b.add(Point{400,200});
kvadrat_b.set_fill_color(Color::blue);

win.attach(kvadrat_b);
win.wait_for_button();

Polygon kvadrat_r;
kvadrat_r.add(Point{300,200});
kvadrat_r.add(Point{300,300});
kvadrat_r.add(Point{400,300});
kvadrat_r.add(Point{400,200});
kvadrat_r.set_fill_color(Color::red);

win.attach(kvadrat_r);
win.wait_for_button();
}


vector<int> calculateSeries(int lånebeløp, int rente, int år){
	vector<int> intVector;
	int gjenståendelån = lånebeløp;
	int innbetaling = 0;
	cout << "År" << setw(12) << "Innbetaling" << endl;
		for (int i = 1; i <= år; i++){
		innbetaling = (lånebeløp/år) + ((rente/static_cast<double>(100))*gjenståendelån);
		intVector.push_back(innbetaling);
		gjenståendelån = (gjenståendelån-(lånebeløp/år));
		cout <<  i << setw(12) << innbetaling << endl;
	}
	return intVector;
}

vector<int> annuitetslån(int lånebeløp, int rente, int år){
	vector<int> annuitetsVector;
	int antallavdrag = år;
	int gjenståendelån = lånebeløp;
	int Innbetaling = 0;
	int avdrag = 0;
	Innbetaling = (lånebeløp)*((rente/100.0)/(1-pow((1+(rente/100.0)), -antallavdrag)));
	cout << "År" << setw(12) << "Innbetaling" << endl;
	for (int i = 1; i <= år; i++){
		annuitetsVector.push_back(Innbetaling);
		avdrag = Innbetaling - ((rente)/100.0)*gjenståendelån;
		gjenståendelån = gjenståendelån - avdrag;
		cout <<  i << setw(12) << Innbetaling << endl;
	}
	return annuitetsVector;
}

void skrivut(int lånebeløp, int rente, int år){
	vector<int> serie = calculateSeries(lånebeløp,rente,år);
	vector<int> annuitet = annuitetslån(lånebeløp,rente,år);
	vector<int> differanseVector;
	int differanse = 0;
	cout << setw(14) << "År" << setw(14) << "Annuitet" << setw(14) << "Serie" << setw(14) << "Differanse" << endl;
	for (int i = 0; i < år; i++){
		cout << setw(14) << i + 1 << setw(14) << annuitet[i] << setw(14) << serie[i] << setw(14) << annuitet[i] - serie[i] << endl;
		differanse = annuitet[i] - serie[i];
		differanseVector.push_back(differanse);
	}
	cout << setw(14) << "Total" << setw(14) << accumulate(annuitet.begin(),annuitet.end(),0) << setw(14) << accumulate(serie.begin(),serie.end(),0) << setw(14) << accumulate(differanseVector.begin(),differanseVector.end(),0) << endl;
}


// C++ programs s
//tart by executing the function main

int main() {
	// printHumanReadableTime(10000);
	//skrivut(10000, 3, 10);
		
	int x = -1;
	while (x != 0) {
	cout << "Velg funksjon:"<<endl;
	cout << "Summer to tall"<<endl;
	cout << "0) Avslutt"<<endl;
	cout << "1) Summer to tall"<<endl;
	cout << "2) Summer flere tall"<<endl;
	cout << "3) Konverter NOK til EURO."<<endl;
	cout << "4) Gangetabell"<<endl;
	cout << "5) Andregradslikning"<<endl;
	cout << "6) Pythagoras"<<endl;
	cout << "7) CalculateSeries"<<endl;
	cout << "8) calculateAnnuity"<<endl;
	cout << "9) 6c"<<endl;
	cout << "Angi valg (0-3):"<<endl;
	cin >> x;
		switch(x) {
		case 1:
		inputIntegersAndPrintSum();
		break;
		case 2:
		summerev2();
		break;
		case 3:
		noktoeuro();
		break;
		case 4:
		gangetabell();
		break;
		case 5:
		solveQuadricEquation();
		break;
		case 6:
		pythagoras();
		break;
		case 0:
		break;
		case 7:
		calculateSeries(10000,5,10);
		break;
		case 8:
		annuitetslån(10000,5,10);
		break;
		case 9:
		skrivut(10000,3,10);
		break;
		default:
		cout << "Du skrev inn et ugyldig tall";
		}
	}
	
	
	
//gangetabell();

//a) inputAndPrintInteger();

//int number = inputInteger();
//cout << "Du skrev: " << number;

//inputIntegersAndPrintSum();

//d) inputInteger fordi den retunerer og da kan jeg bruke den videre

//e) bool navn = isOdd(0);
//cout << navn << endl;

//f) printHumanReadableTime(10000);

//2a) summere();

//2b)summerev2();

//2c) for i a, og while i b

//2d) double number = inputDouble();
//cout << "Du skrev: " << number << endl;

//2e) noktoeuro();

//2f) inputDouble hvis det er komma, 

keep_window_open();
}

//------------------------------------------------------------------------------
