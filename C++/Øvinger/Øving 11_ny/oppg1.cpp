#include "oppg1.h"

void iteratorer1::task1a(){
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << "\n";
}

void iteratorer1::task1b(){
    for (vector<string>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << "\n";
}

void iteratorer1::replace(vector<string>& v, string old, string replacement){

    for (vector<string>::iterator it = v.begin(); it != v.end(); ++it)
    {
        if (*it == old)
        {
            it = v.erase(it);
            it = v.insert(it,replacement);
        }
        
    }
    for (vector<string>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << "\n";

}


void iteratorer1::task1d_a(){
    for (set<string>::iterator it = settet.begin(); it != settet.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << "\n";
}
void iteratorer1::task1d_b(){
    for (set<string>::reverse_iterator it = settet.rbegin(); it != settet.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << "\n";

}
void iteratorer1::replace_set(set<string>& v, string old, string replacement){
    
    for (set<string>::iterator it = v.begin(); it != v.end(); ++it)
    {
        if (*it == old)
        {
            it = v.erase(it);
            it = v.insert(it,replacement);
        }
        
    }
    for (set<string>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << "\n";

}
