#ifndef SAFE_MATRIX_H
#define SAFE_MATRIX_H

#include <iostream>
#include <cstdlib>
#include "SafeArray.h"
using namespace std;

template <class T>
class SafeMatrix
{
   private:
      int row_size;
      int col_size;
      int curr_row;
      int curr_col;
      T** array;
   public:
      SafeMatrix(int row_size, int col_size);
      SafeMatrix();
      T& operator [] (int index);
      int length() const;
      ~SafeMatrix();
      SafeMatrix(const SafeMatrix<T>& other);
      SafeMatrix<T>& operator = (const SafeMatrix<T>& other);
};

#endif