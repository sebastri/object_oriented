#pragma once

#include "std_lib_facilities.h"

#include <sstream>

void fileTovector(string filename, vector<double>& x, vector<double>& y){
	double xi;
	double yi;
	string comma;
	ifstream ist{filename};
	if (ist.fail()){
		throw "fail";
	}
	string line;
	
	while (getline(ist,line))
	{
		stringstream ss{line};
		while (ss >> xi >> comma >> yi >> comma){
			x.push_back(xi);
			y.push_back(yi);
		}
	}
		
}
// C++ programs start by executing the function main
int main()
{
	vector<double> vec_x;
	vector<double> vec_y;
	fileTovector("test.txt", vec_x, vec_y);



	keep_window_open();
}

//------------------------------------------------------------------------------
