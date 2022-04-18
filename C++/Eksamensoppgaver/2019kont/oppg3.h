#pragma once
#include "std_lib_facilities.h"
#include "Graph.h"

using namespace Graph_lib;

struct Location {
    string name;
    Point p;
   Location(string str, Point pt):name{str}, p{pt}{}
};

class Bikestation{
    private:
    int dispWidth = 400;
    int dispHeight = 600;
    Location loc;
    unsigned int capacity;
    unsigned int bikes;
    Vector_ref<Shape> display;
    public:
    Bikestation(Location where, unsigned int cap, unsigned int numBikes):loc{where},capacity{cap},bikes{numBikes}
    {
        Rectangle* r = new Rectangle(loc.p, dispWidth, dispHeight);
        r->set_fill_color(Color::white);
        display.push_back(r);

        Text* t = new Text(loc.p, loc.name);
        t->set_color(Color::blue);
        t->set_font_size(20);
        display.push_back(t);

        Text* t2 = new Text(Point{loc.p.x+2, loc.p.y+15}, status());
        t2->set_color(Color::black);
        display.push_back(t2);
    }

    void setBikes(unsigned int b){bikes=b;}
    unsigned int getBikes() const{return bikes;}
    string getName(){return loc.name;}
    string status(){return to_string(bikes) + " out of " + to_string(capacity);}
    unsigned int getCapacity();

    map<string, int> simulateOneDay(vector<Bikestation*> vec){
        int ridesPerDay=100;
        
        map<string, int> sykkeltur;

        for (size_t i = 0; i < ridesPerDay; i++)
        {
            int randomFrom = rand()%vec.size();
            int randomTo = rand()%vec.size();
            while (randomFrom == randomTo){

                randomTo = rand() % vec.size();
            }
            auto bikesFrom = vec[randomFrom]->getBikes();
            auto bikesTo = vec[randomTo]->getBikes();
            if (vec[randomFrom]->getCapacity() >0 && vec[randomTo]->getCapacity() - bikesTo >0)
            {
                vec[randomFrom]->setBikes(--bikesFrom);
                vec[randomTo]->setBikes(++bikesTo);
            }
            else{
                sykkeltur[vec[randomFrom]->getName()]++;
            }
        }
        return sykkeltur;
    }   
    void printStats(map<string, int> tur){
        cout << "Unsuccessful rides:" << endl;
        for (auto p:tur){
            cout << p.second << " bike trips refused at " << p.first << endl;
        }
        cout << endl;
    }
};


