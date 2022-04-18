#pragma once
#include "std_lib_facilities.h"

struct Obs {
int x;
int y;

vector<Obs> openfile(string filename);
void report(vector<Obs> vec, int threshold);

};

bool operator<(Obs lhs,Obs rhs);