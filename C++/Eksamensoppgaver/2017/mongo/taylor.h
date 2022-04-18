#pragma once
#include "std_lib_facilities.h"
int NFAC_LIMIT = 2;
double radian(double degree);

double nFac(unsigned int n);

double sineTaylorTerm(double x, int n);

double sineTaylor(double x, int n);


int testTaylor(double degree, double epsilon);

double nFacRobust(unsigned int n);

void testnFaceRobust();
