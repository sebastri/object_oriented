#include "taylor.h"

double radian(double degree){
return (degree/360.0)*2*_Pi;
}

double nFac(unsigned int n){
    unsigned int no = n;
    if(n == 0){return 1;}
    for (int i = 1; i < no; i++)
    {
        n=n*i;
    }
    return n;
}
double sineTaylorTerm(double x, int n){
    return pow(-1.0, n)*pow(x, (2*n)+1)/(nFac((2*n)+1));
}



double sineTaylor(double x, int n){
    double sum = 0;
    for (int i = 0; i < n+1; i++)
    {
        sum += sineTaylorTerm(x,i);
    }
    return sum;
}

int testTaylor(double degree, double epsilon) {
double estim = 0.0;
int terms = 0;
double rad = radian(degree);
estim += sineTaylorTerm(rad, terms);
while (abs(sin(rad) - estim) > epsilon) {
    terms++;
    estim += sineTaylorTerm(rad, terms);
}
return(terms + 1);
}

/*
int testTaylor(double degree, double epsilon){
    int n = 0;
    double number = sin(radian(degree));
    bool b = true;
    while (b)
    {
        
        if (abs(sineTaylor(radian(degree), n)-number) < epsilon)
        {
            b = false;
        }
        n++;
        
    }
    return (n); 
}
*/
double nFacRobust(unsigned int n){
    if (n>NFAC_LIMIT)
        throw n;
    
    else 
    return (nFac(n));
}

void testnFacRobust(){
    int testCase[3] = {0, 8, NFAC_LIMIT +1};
    for (int i = 0; i < 3; i++)
    {
        double nFacValue = 0.0;
        try{
            nFacValue = nFacRobust(testCase[i]);
        }
        catch (unsigned int e){
            cout << "Error, too large input: " << e << endl;
            continue;  
        }
    }
    
}