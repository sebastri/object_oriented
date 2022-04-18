#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

class iteratorer1{
    vector<string> vec{"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectetur"};
    set<string> settet{"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectetur"};
    
    public:
    
    void task1a();
    void task1b();
    void replace(vector<string>& v, string old, string replacement);

    void task1d_a();
    void task1d_b();
    void replace_set(set<string>& v, string old, string replacement);



};

