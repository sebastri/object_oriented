#include "utilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
for (int i = 0; i < numTimes; i++) {
startValue += increment;
}
return startValue;
}

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes){
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
}

void swapNumbers(int& verdi1, int& verdi2){
    int a = verdi1;
    verdi1 = verdi2;
    verdi2 = a;
    //cout << "verdi1: " << verdi1 << " verdi2: " << verdi2 << "\n";
}

void randomizeVector(vector<int>& vec, int n){
    for (int i = 0; i < n; i++){
        vec.push_back(rand() % 101);
    }
}

void sortVector(vector<int>& vec){
    unsigned int i = 1;
    while (i < vec.size()){
        int j = i;
        while (j > 0 && vec[j-1] > vec[j]){
            swapNumbers(vec[j], vec[j-1]);
            j=j-1;
        }
        i=i+1;
    }
}

void medianOfVector(vector<int>& vec){
    double median = 0;
    if (vec.size() % 2){
        median = vec[vec.size()/2];
    }
    else {
        median = (vec[(vec.size()/2)-1]+ vec[(vec.size()/2)])/static_cast<double>(2);
    }
    cout << "Medianen er: " << median << "\n";
}

void printStudent(Student me){
    cout << "Name: " << me.name << "\n";
    cout << "Age: " << me.age << "\n";
    cout << "Studyprogram: " << me.studyProgram << "\n";
}

string randomizeString(int n, char downlimit, char upperlimit){
    string str;
    for (int i = 0; i < n; i++){
        str += (downlimit) + rand()%(upperlimit-downlimit);
    }
    return str;
}

string readInputToString(int n, char downlimit, char upperlimit){
    string str;
    char x = 0;
    int i = 0;
    while (i < n){
        cout << "Skriv inn en bokstav innenfor grensen(" << downlimit << ", " << upperlimit << ") : \n";
        cin >> x;
        if (downlimit <= x && x <= upperlimit){
            str += x;
            i += 1;
        }
            else if(downlimit + 32 <= x && x <= upperlimit + 32){
                str += x - 32;
                i += 1;
            }    
        else{
            cout << "Bokstaven er ikke innenfor grensen!\n";
        }   
    }
    cout << str << "\n";
    return str;
}

int countChar(string str, char ch){
    int x = 0;
    for (unsigned int i = 0; i < str.size(); i++){
        if (str[i]==ch)
        x+=1;
    }
    return x;
}