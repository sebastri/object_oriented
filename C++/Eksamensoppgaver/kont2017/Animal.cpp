#include "Animal.h"

Animal *Animal::parseAnimal(string line){
        stringstream ss(line);
        string name;
        string type;
        int age;
        string tmp;

        ss >> name;
        ss >> tmp;
        ss >> type;
        ss >> tmp;
        ss >> age;
        if (type == "Dog")
        {
            string color;
            ss >> tmp;
            ss >> color;
            return new Dog(name, age, color);
        }
        else if (type == "Human"){
            return new Human(name, age);
        }
    return nullptr;
}

void Animal::parseFriends(map<string, Animal *> &animals, string line){
    stringstream sss{line};
    string tmp;
    string name1;
    string name2;
    int age;
    string tmp;

    sss >> name1;
    sss >> tmp;
    sss >> name2;

    if (animals.find(name1) == animals.end() || animals.find(name2) == animals.end())
    {
        cout << "feil";
    }
    animals[name1]->addFriend(animals[name2]);
    animals[name2]->addFriend(animals[name1]);
}   

map<string, Animal *> Animal::readAnimals(string filename){
    map<string, Animal *> map;
    ifstream ist{filename};
    string line;
    
    if (!ist) throw "cant open input file";
    
    while (getline(ist, line))
    {
        stringstream ss{line};
        string first;
        string second;
        ss >> first;
        ss >> second;
        if (second == "the")
        {
            map[parseAnimal(line)->getName()] = parseAnimal(line);
            
        }
        else if (second == "and"){
            ss >> second;
            parseFriends(map, line);
        }
        
    }
    return map;
}