#pragma once
#include "std_lib_facilities.h"


class CourseCatalog{
    
    public:
    void addCourse(string emnekode, string emnenavn);
    void removeCourse(string emnekode);//fjerner kurs gitt emnekode
    string getCourse(string emnekode);//finner emnenavn gitt emnekode
    friend ostream& operator<<(ostream& os, const CourseCatalog& emne);//skrive ut alle emnekoder med emnenavn
    void loadData(string filename);
    void saveData(string filename);



    private:
    map<string, string> mapemnekoder;

};

void testCatalog();