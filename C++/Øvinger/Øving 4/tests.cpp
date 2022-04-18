#include "std_lib_facilities.h"
#include "tests.h"


void testCallByValue() {
int v0 = 5;
int increment = 2;
int iterations = 10;
int result = incrementByValueNumTimes(v0, increment, iterations);
cout << "v0: " << v0
<< " increment: " << increment
<< " iterations: " << iterations
<< " result: " << result << endl;
}

void testCallByReference() {
int v0 = 5;
int increment = 2;
int iterations = 10;
incrementByValueNumTimesRef(v0, increment, iterations);
cout << "v0: " << v0
<< " increment: " << increment
<< " iterations: " << iterations
<< " result: " << v0 << endl;
}

void testVectorSorting(){
    vector<int> percentages;
    randomizeVector(percentages, 10);
    for (unsigned int i = 0; i < percentages.size(); i++){
        cout << percentages[i] << ' ';
    }
    cout << "\n";
    swapNumbers(percentages[0],percentages[1]);
    for (unsigned int i = 0; i < percentages.size(); i++){
        cout << percentages[i] << ' ';
    }
    cout << "\n";

    cout << "Vil du sortere? Hvis ja skriv: 1, hvis ikke skriv: 0\n";
    
    int x = 0;
    cin >> x;
    if (x == 1){
        sortVector(percentages);
        for (unsigned int i = 0; i < percentages.size(); i++){
        cout << percentages[i] << ' ';
    }
    cout << "\n";
    }
    medianOfVector(percentages);

}

void teststruct (){
    Student me;
	    me.name="Sebastian";
	    me.age=20;
	    me.studyProgram="EMIL";
        printStudent(me);
}

void testString(){
    string grades;
    grades += randomizeString(8,'A','F');
    cout << grades << "\n";
    int ant = 0;
    vector<int> gradeCount;
    for (unsigned int i = 0; i < grades.size(); i++){
        gradeCount.push_back(countChar(grades, 'A' + i));
        ant += (5-i)*gradeCount[i];
    }
    cout << "Gjennomsnitt: " << static_cast<double>(ant)/gradeCount.size() << "\n";
}


