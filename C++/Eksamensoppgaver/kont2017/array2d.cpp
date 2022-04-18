#include "array2d.h"

ostream& operator<<(ostream& out,  Array2D& a){
  
  for (int i = 0; i < a.getYdim(); i++)
  {
    for (int j = 0; j < a.getXdim(); j++)
    {
        out << a[i][j] << " ";
    }
    out << endl;
  }
  return out;
}

