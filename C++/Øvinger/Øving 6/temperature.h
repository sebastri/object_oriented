#pragma once
#include "std_lib_facilities.h"

class Temps{
    public:
    void tempFromFile(string filename);
    void addMaxMin(float max, float min);


    private:
    map<float, float> maxmin;
};