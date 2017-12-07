#ifndef SAFE_MATRIX_H
#define SAFE_MATRIX_H

#include <iostream>
#include <cstdlib>
#include "SafeArray.h"
using namespace std;

template <typename T >
class SafeMatrix
{
   private:
      int row_size;
      int col_size;
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


template <typename T>
SafeMatrix<T>::SafeMatrix(): row_size(1), col_size(1)
{ 
    array[row_size] = new SafeArray<T>*(col_size);
}

template <typename T>
SafeMatrix<T>::SafeMatrix(int row_size, int col_size) : row_size(row_size), col_size(col_size)
{
   if (row_size < 0 || col_size < 0)
   {
      cout << "Array size cannnot be negative." << endl;
      exit(1);
   } 
   array = new T*[row_size];
   for(int i = 0; i < row_size; i++){
        array[i] = new T(col_size);
   }
}

template <typename T>
T& SafeMatrix<T>::operator [] (int index)
{
   if (index < 0 || index >= row_size)
   {
      cout << "Array index: " << index << " is out of bounds." 
           << endl;
      exit(1);
   }
   return *array[index];
}

template <typename T>
int SafeMatrix<T>::length() const
{
   return row_size;
}


template <typename T>
SafeMatrix<T>::~SafeMatrix()
{
   if (array != NULL)
   {
        for(int i = 0; i < row_size; i++){
            delete array[i];
        }
        delete [] array;
        array = NULL;
   }
}


template <typename T>
SafeMatrix<T>::SafeMatrix(const SafeMatrix<T>& other) : row_size(other.row_size)
{
   array = new SafeArray<T>*[row_size];

   for (int i = 0; i < row_size; i++)
   {
      array[i] = other.array[i];
   }
}

template <typename T>
SafeMatrix<T>& SafeMatrix<T>::operator = (const SafeMatrix<T>& other)
{
   if (this != &other)
   {
      if (array != NULL)
      {
        for(int i = 0; i < row_size; i++){
            delete array[i];
        }
        delete [] array;
        array = NULL;
      }
      row_size = other.row_size;
      array = new SafeArray<T>*[row_size];
      for (int i = 0; i < col_size; i++)
      {
         array[i] = other.array[i];
      }
   }
   return *this; 
}

#endif