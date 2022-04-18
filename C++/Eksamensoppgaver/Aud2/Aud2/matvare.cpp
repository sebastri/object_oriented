#pragma once
#include "std_lib_facilities.h"

struct Food {
string name;
double price;
string where;
};

bool operator<(const Food& a,const Food& b){
    return (a.price < b.price);
}

void addPrice(map<string, set<Food>>& db, Food fp){
    db[fp.name].insert(fp);
}

void printAllPrices(const map<string, set<Food>>& db){
    for(auto i:db){
        cout << i.first <<":\n";
        for (auto it = i.second.begin(); it != i.second.end(); ++it)
        {
            cout << it->price << " " << it->where << endl;
        }
    }
}

void bestPrice(const map<string, set<Food>>& db, string name){
    for(const auto i:db){
        if (name == i.first)
        {
            auto it = i.second.begin();
            cout << "Best price for " << name << " is " << it->price << " at " << it->where;
            return;
        }
    }
    cout << "No price for " << name;
}