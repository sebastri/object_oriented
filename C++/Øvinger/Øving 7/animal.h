#pragma once
#include "std_lib_facilities.h"
#include "Graph.h"
using namespace Graph_lib;


class Animal{
    private:

    protected:
    string name;
    int age;

    public:
    Animal(string n, int a): name(n), age(a){}
    virtual string toString()=0; //må overskride denne funksjon hvis den kalles
    //abtract class er når den har en pure virtual function
};

class Cat : public Animal
{
    
    public: 
    string toString();
    Cat(string n, int a):Animal(n,a){}

};

class Dog : public Animal
{
    public: 
    string toString();
    Dog(string n, int a):Animal{n,a}{}

};

void testAnimal();
