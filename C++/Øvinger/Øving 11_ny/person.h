#pragma once
#include <string>
#include <iostream>
#include <list>



using namespace std;


class Person{
    string fornavn;
    string etternavn;
    

    public:
    Person() : fornavn{"noname"}, etternavn{"noname"}{}
    Person(string f, string e): fornavn{f}, etternavn{e}{}
    string getFirstName() const {return fornavn;};
    string getSurName() const {return etternavn;};
    
    //Person& operator<(const Person& p);
};
void insertOrdered(list<Person> &l, const Person& p);
ostream& operator<<(ostream& out, const Person& p);