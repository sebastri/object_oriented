#include "emnekatalog.h"
#include "std_lib_facilities.h"

void CourseCatalog::addCourse(string emnekode, string emnenavn){
   
    mapemnekoder[emnekode] = emnenavn;
}
 

ostream& operator<<(ostream& out, const CourseCatalog& emne){
    for (const auto& i: emne.mapemnekoder){
        out << "Emnekode: " << i.first << " Emnenavn: " << i.second << endl;
    }
    return out;
}

void CourseCatalog::removeCourse(string emnekode){
    // cout << "Skriv inn emnekode som du vil fjerne fra mappet: ";
    // string emnekode;
    // cin >> emnekode;
    mapemnekoder.erase(mapemnekoder.find(emnekode));
    cout << emnekode << " fjernet" << endl;
}

string CourseCatalog::getCourse(string emnekode){
    //cout << "Skriv inn emnekode som du vil ha emnenavnet til: ";
    // string emnekode;
    // cin >> emnekode;
    cout << mapemnekoder.at(emnekode) << endl; 
    return mapemnekoder.at(emnekode);
}

void CourseCatalog::loadData(string filename){
    ifstream ist{filename};
    if(!ist) error("cannot open the input file", filename);

    string line;
    string emnekode;
    string emnenavn;

    while(!ist.eof()){
        getline(ist, line);
        if(!line.empty()){
        emnekode = line.substr(0, line.find('|'));
        emnenavn = line.substr(line.find('|') + 1, line.back());
        addCourse(emnekode, emnenavn);
        }
    }
}

void CourseCatalog::saveData(string filename){
    ofstream ost{filename};
    if(!ost) error("cannot open the output file", filename);
    for (auto i:mapemnekoder){
        ost << i.first << "|" << i.second << endl;
    }
}


void testCatalog(){
    CourseCatalog myobj;
    myobj.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
    myobj.addCourse("TDT4102","Prosedyre- og objektorientert programmering");
    myobj.addCourse("TMA4100","Matematikk 1");
    cout << myobj << endl;

    //delete Matte 1

    myobj.removeCourse("TMA4100");
    cout << myobj << endl;

    //Oppgave 3d)
    myobj.addCourse("TDT4102", "C++");
    cout << myobj << endl;

    //Oppgave 3e)
    myobj.saveData("lagring.txt");
    //myobj.loadData("lagring.txt");

}