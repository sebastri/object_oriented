#pragma once
#include "std_lib_facilities.h"

class Animal{
    protected:
    string name;
    int age;
    vector <Animal *> friends;

    public:

    Animal(string name, int age):name{name}, age{age}{}

    virtual string toString(){
        return name + " the animal";
    }

    string getName(){
        return name;
    }
    void addFriend(Animal *a){
        friends.push_back(a);
    }
    vector <Animal *> getFriends(){
        return friends;
    }
    Animal *parseAnimal(string line);

    void parseFriends(map<string, Animal *> &animals, string line);

    map<string, Animal *> readAnimals(string filename);
};

class Dog : public Animal{
    protected:
    string color;
    public:
    Dog(string name, int age, string color): Animal(name, age), color{color}{}
    
    virtual string toString(){
        return name + " the Dog";
    }
};

class Human : public Animal{
    
    public:
    Human(string name, int age): Animal(name, age){}
    
    virtual string toString(){
        return name + " the Human";
    }
};