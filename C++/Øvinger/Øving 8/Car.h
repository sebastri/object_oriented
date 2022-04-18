#pragma once
#include "std_lib_facilities.h"


class Car{
    private:
    int freeSeats;
    public:
    Car(int getfreeSeats) : freeSeats{getfreeSeats}{};
    bool hasFreeSeats() const; //endrer ikke objektet
    void reserveFreeSeat();
};

class Person{
    private:
    string name;
    string email;
    Car* car; //peker på minneadressen, kan ikke sette et object lik en int, må gå via adressen, derfor brukes pointer

    public:
    Person(string navn, string mail, Car* bil = nullptr): name{navn}, email{mail}, car{bil}{};
    void setName(string na);
    string getName();
    void setEmail(string em);
    string getEmail();
    bool hasAvailableSeats();
    friend ostream& operator<<(ostream& out, const Person& p);
};
