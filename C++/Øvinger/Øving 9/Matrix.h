#pragma once
#include "minne.h"


class Matrix{
    private:
    double** matrix;
    int row;
    int col;
    


    public:
    Matrix():matrix{nullptr}{};
    Matrix(int nRows, int nColumns);
    explicit Matrix(int nRows);
    Matrix(const Matrix& rhs);

    Matrix& operator=(Matrix rhs);
    Matrix& operator+=(Matrix& m);
    Matrix& operator+(Matrix& m);

    double get(int row, int col) const;
    void set(int row, int col, double val);
    int getRows() const;
    int getColumns() const;
    bool isValid() const;
    ~Matrix();
    friend ostream& operator<<(ostream& out, Matrix& m);
};