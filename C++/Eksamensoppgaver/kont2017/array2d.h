#pragma once
#include "std_lib_facilities.h"

class Array2D {
private:
int xdim;    // Number of columns
int ydim;    // Number of rows
float *data; // Dynamic 1D array to hold data
public:


friend ostream& operator<<(ostream& out,  Array2D& a);

Array2D(int xdim, int ydim, float fill=0.0):xdim(xdim), ydim(ydim), data (new float [xdim*ydim]){
    for (int i = 0; i < xdim*ydim; i++)
    {
        data[i] = fill;
    }
}

Array2D(const Array2D &other){
    xdim=other.xdim;
    ydim=other.ydim;
    data = new float[xdim*ydim];
    for (int i = 0; i < size(); i++)
    {
        data[i]=other.data[i];
    }
}
~Array2D(){
    delete[] data;
}

Array2D& operator=(Array2D rhs){
    swap(data, rhs.data);
    swap(xdim, rhs.xdim);
    swap(ydim, rhs.ydim);
    return *this;
}

unsigned int getXdim() const { return xdim; }
unsigned int getYdim() const { return ydim; }
int size() { return xdim * ydim; }

float *operator[](int i){
  return &data[i * xdim];
}



float min(){
    float temp = data[0];
    for (int i = 0; i < size(); i++)
    {
        if(temp>data[i]){
            temp = data[i];
        }
    }
    return temp;
}
};

