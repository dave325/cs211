#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include "Book.h"

using namespace std;

class Library{
public:
    Library();
    Library(int size);
    Library(const Library& other);
    ~Library();
    int getSize();
    void addBook(const Book& b);
    Book& operator[](int i) const;
    friend ostream& operator<<(ostream& os, const Library& b);
private:
    void grow();
    int size;
    int capacity;
    Book* lib;
};
#endif