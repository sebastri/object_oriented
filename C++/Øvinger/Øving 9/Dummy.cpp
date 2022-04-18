#include "Dummy.h"

void dummyTest() {
Dummy a;
*a.num = 4;
Dummy b{a};
Dummy c;
c = a;
cout << "a: " << *a.num << endl;
cout << "b: " << *b.num << endl;
cout << "c: " << *c.num << endl;
*b.num = 3;
*c.num = 5;
cout << "a: " << *a.num << endl;
cout << "b: " << *b.num << endl;
cout << "c: " << *c.num << endl;
cin.get(); // For å hindre at
// programmet avslutter med en gang
}

Dummy& Dummy::operator=(Dummy a){
   std::swap(num, a.num); // a ender opp med det som skal slettes, destruktøren blir kalt når den går ut av scope
   return *this;
};