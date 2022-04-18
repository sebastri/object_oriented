#include "person.h"


ostream& operator<<(ostream& out, const Person& p){
  return  out << p.getFirstName() << " " <<  p.getSurName() << endl;
}


void insertOrdered(list<Person> &l, const Person& p){
    
    
    for (auto it = l.begin(); it != l.end(); ++it)
    {
        if (p.getFirstName() < it->getFirstName())
        {
            it = l.insert(it, p);
            return;
        }
        
    }
    l.push_back(p); // hvis ikke navnet er mindret enn noe i lista så legges den til bakerst
    
}