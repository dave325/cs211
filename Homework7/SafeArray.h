#ifndef SAFE_ARRAY_H
#define SAFE_ARRAY_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class SafeArray
{
   private:
      T* array;
      int size;

   public:
      SafeArray(int s);
      SafeArray();
      T& operator [] (int index);
      int length() const;
      ~SafeArray();
      SafeArray(const SafeArray<T>& other);
      SafeArray<T>& operator = (const SafeArray<T>& other);
};


#endif