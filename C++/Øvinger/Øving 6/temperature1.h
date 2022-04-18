#pragma once
#include "std_lib_facilities.h"

class Temps{
    private:
    float max;
    float min;
    
    public:
    friend istream& operator>>(istream& is, Temps& t);
    
};
vector<Temps> getTempsFromFile(string filename);