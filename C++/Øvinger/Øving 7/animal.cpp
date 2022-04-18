#include "animal.h"

/*Animal::Animal(string n, int a): name(n), age(a)
{
    //name = n;
    //age = a;
}
*/

string Animal::toString(){
    return "Animal: " + name + ", " + to_string(age);
}

string Cat::toString(){
    return "Cat: " + name + ", " + to_string(age);
}

string Dog::toString(){
    return "Dog: " + name + ", " + to_string(age);
}

void testAnimal(){
    //Animal animal{"Simba", 3};
    Cat cat{"Prikken", 5};
    Dog dog{"Pluto", 6};
    Vector_ref<Animal> vec;
    //vec.push_back(animal);
    vec.push_back(cat);
    vec.push_back(dog);

    for (unsigned int i = 0; i < vec.size(); i++)
    {
        cout << vec[i].toString() << endl;
    }
    

}