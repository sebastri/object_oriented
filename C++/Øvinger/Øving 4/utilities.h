#pragma once
#include "tests.h"
int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);
void swapNumbers(int& verdi1, int& verdi2);
void randomizeVector(vector<int>& vec, int n);
void sortVector(vector<int>& vec);
void medianOfVector(vector<int>& vec);
struct Student{
    string name;
    string studyProgram;
    int age;
};
void printStudent(Student me);
string randomizeString(int antTegn, char downlimit, char upperlimit);
string readInputToString(int antTegn, char downlimit, char upperlimit);
int countChar(string str, char ch);