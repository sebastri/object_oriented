#include "temperature1.h"

istream& operator>>(istream& is, Temps& t){
    is >> t.max >> t.min;  
    // Dette fungere fint siden vi antar at filen er 
    //strukturert på samme måte hele veien. 
    //To flyttall på en linje, etterfulgt av to nye flyttall på en linje, osv, helt til slutten av filen. 
    //Whitespace, mellomrom, linjeskift, osv, tolkes som "ingenting" av input-operatoren du har definert og det er bare flyttall i par som leses inn i et Temps-objekt.
    return is;
}
    
vector<Temps> getTempsFromFile(string filename){
    ifstream ifs{filename};
    vector<Temps> temps;
    Temps temperatures;
    if(!ifs) error("could not open file");
    while(!ifs.eof()){
        ifs >> temperatures;
        temps.push_back(temperatures);
    }
    return temps;
}