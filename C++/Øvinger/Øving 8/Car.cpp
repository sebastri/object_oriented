#include "Car.h"

bool Car::hasFreeSeats() const{
if(freeSeats>0){
    return true;
}
else{
    return false;
}
}

void Car::reserveFreeSeat(){
    freeSeats--;
}
void Person::setName(string na){
    name = na;
}


string Person::getName(){
    return name;
}

void Person::setEmail(string em){
    email = em;
}
string Person::getEmail(){
    return email;
}

bool Person::hasAvailableSeats(){
    if(car != nullptr){
        return car->hasFreeSeats(); //fjerner peking
    }
    else{
        return false;
    }
}
ostream& operator<<(ostream& out, const Person& p){
  return  out << p.name <<  p.email << p.car << endl; //må overlaste cout operatoren fordi man kan ikke bare skrive ut en person
}