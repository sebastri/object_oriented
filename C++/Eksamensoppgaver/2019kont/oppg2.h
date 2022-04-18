#pragma once
#include "std_lib_facilities.h"

double sum(vector<double>& x){
    double sum = 0;
    for (double x0: x)
    {
        sum += x0;
    }
    return sum; 
}

double mean(vector<double>& x){
    return sum(x)/x.size();
}



void read_csv(string filename, vector<double>& x, vector<double>& y){
    double xi;
    double yi;
    ifstream ist{filename};
    if (ist.fail())
    {
        throw "Couldn't read file" + filename;
    }
    string line;
    string comma;
    while (getline(ist,line))
    {
        stringstream ss{line};
        ss >> xi;
        x.push_back(xi);
        ss >> yi;
        y.push_back(yi);
    }
    ist.close();
}

pair<double, double> linreg(vector<double>& x, vector<double>& y){
    double var;
    double cov;
    double meanx = mean(x);
    double meany = mean(y);
    for (int i = 0 ; i < x.size(); i++)
    {
        var += (x[i]-meanx)*(x[i]-meanx);
        cov += (x[i]-meanx)*(y[i]-meany);

    }
    double a = cov/var;
    double b = meany - a*meanx;
    return {a,b};
}

vector<double> linpred(vector<double>& x, double a, double b){
    vector<double> yvec;
    for(auto i:x){
        yvec.push_back(a*i + b);
    }
    return yvec;
}
double r2(vector<double>& y, vector<double>& y_pred){
    double teller;
    double nevner;
    double ymean = mean(y);
    for (int i = 0; i < y_pred.size(); i++)
    {
        teller += (y[i]-y_pred[i])*(y[i]-y_pred[i]);
        nevner += (y[i]-ymean)*(y[i]-ymean);
    }
    return 1- (teller/nevner);
}

void mainfunksjon(){
    vector<double> x;
	vector<double> y;
    read_csv("data.csv", x, y);
    pair p = linreg(x,y);
    vector<double> y_pred =linpred(x, p.first,p.second);
    double R2 = r2(y,y_pred);
    cout << p.first << " " << p.second << " " << R2 << endl;

}