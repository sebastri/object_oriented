#include "Matrix.h"

Matrix::Matrix(int nRows, int nColumns):row{nRows},col{nColumns}{
    matrix = new double*[row]; //setter av plass i minnet til av (antall row) pekere (peker på peker)
    for (int i = 0; i < row; i++)
    {
        matrix[i] = new double[col]; //setter (antall col) arrays som er plassert i minne
        
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = 0; // setter av en faktisk verdi
        }
    } 
}

Matrix::Matrix(const Matrix& rhs)
{
    col = rhs.col;
    row = rhs.row;
    matrix = new double*[row];

    for (int i = 0; i < row; i++)
    {
        matrix[i] = new double[col]; 
        
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = rhs.get(i,j);
        }
    } 
}

Matrix& Matrix::operator=(Matrix rhs){
    std::swap(row, rhs.row);
    std::swap(col, rhs.col);
    std::swap(matrix, rhs.matrix);
    return *this;
}

Matrix& Matrix::operator+=(Matrix& m){
    if (this->col==m.getColumns() && this->row==m.getRows())
    {
        for (int i = 0; i < m.getRows(); i++){
        
            for (int j = 0; j < m.getColumns(); j++)
            {
            matrix[i][j] += m.get(i,j);  //A[i][j] += B.get(i,j)
            }
        }
        return *this;
    }
    else
    {
        matrix = nullptr;
        return *this;
        cout << "Ugyldig matrise!\n";
    }
    
}

Matrix& Matrix::operator+(Matrix& m){
    if (this->col==m.getColumns() && this->row==m.getRows())
    {
        for (int i = 0; i < m.getRows(); i++){
        
            for (int j = 0; j < m.getColumns(); j++)
            {
            matrix[i][j] += m.get(i,j);  //A[i][j] += B.get(i,j)
            }
        }
        return *this;
    }
    else
    {
        matrix = nullptr;
        return *this;
        cout << "Ugyldig matrise!\n";
    }    
}


Matrix::Matrix(int nRows):row{nRows}, col{nRows}{
    matrix = new double*[row]; //allocate an array of row double pointers
    for (int i = 0; i < row; i++)
    {
        matrix[i] = new double[col]; //these are our colums

        for (int j = 0; j < col; j++)   
        {
            if (i==j)
            {
                matrix[i][j] = 1; //accsess array og setter verdi til 1
            }
            else{
                matrix[i][j] = 0;
            }
        }
    }
}

Matrix::~Matrix(){
    for (int i = 0; i < row; i++)
    {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
}

double Matrix::get(int row, int col) const {
    return matrix[row][col]; //access array
}

void Matrix::set(int rows, int cols, double value){
    matrix[rows][cols] = value;
}

int Matrix::getRows() const{
    return row;

}
int Matrix::getColumns() const{
    return col;
}

bool Matrix::isValid() const{
    if (matrix == nullptr)
    {
        return false;
    }
    else{
        return true;
    }
}

ostream& operator<<(ostream& out, Matrix& m){
    if (!m.isValid())
    {
        out << "\nUgyldig matrise!\n";
    }

    for (int i = 0; i < m.getRows(); i++)
    {
        for (int j = 0; j < m.getColumns(); j++)
        {
            out << m.get(i,j) << " ";
        }
        out << endl;
    }
    return out;
}

