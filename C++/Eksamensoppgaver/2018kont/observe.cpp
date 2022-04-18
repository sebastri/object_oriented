#include "observe.h"

vector<Obs> Obs::openfile(string filename){
    ifstream ist{filename};
    if (!ist) error("feil", filename);
    vector<Obs> obs;
    string line;
    while (getline(ist, line))
    {
        Obs next;
        string x;
        string y;
        stringstream ss{line};
        ss >> x;
        if (x == "-1")
        {
            return obs;
        }
        ss >> y;
        next.x = stoi(x);
        next.y = stoi(y);
        obs.push_back(next);
    }
}

bool operator<(Obs lhs, Obs rhs){
    return ((lhs.x<rhs.x) || ((lhs.x == rhs.x) && lhs.y < rhs.y));   
}

void Obs::report(vector<Obs> vec, int threshold){
    map<Obs, int> map;
    for(auto p:vec){
        map[p]++;
    }
    for (auto p:map)
    {
        if (p.second > threshold)
        {
            std::cout << p.first.x << " " << p.first.y << " " << p.second << endl;
        } 
    }
}