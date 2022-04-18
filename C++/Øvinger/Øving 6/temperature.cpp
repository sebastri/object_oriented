#include "temperature.h"



void Temps::addMaxMin(float max, float min){
    maxmin.insert(pair<float,float>(max, min));
}

void Temps::tempFromFile(string filename){
    ifstream ifs{filename};
    if(!ifs) error("could not open file");
    string line;
    while(!ifs.eof()){
        getline(ifs, line);
        if(!line.empty()){
        float max = stod(line.substr(0,line.find('\t')));
        float min = stod(line.substr(line.find('\t')+1, line.back()));
        addMaxMin(max, min);
        }
    }
}