#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> vec{"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectetur"};


void task1a(){
    

    for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << " ";
    }
    
}
