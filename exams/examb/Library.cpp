#include "Library.h"
#include <iostream>
#include "Book.h"
using namespace std;
Library::Library(){
    capacity = 1;
    size = 0;
    lib = new Book[capacity];
}

Library::Library(int cap){
    capacity = cap;
    size = 0;
    lib = new Book[capacity];
}

// Copy Constructor for the class
Library::Library(const Library& other) {
    size = other.size;
    capacity = other.capacity;
    lib = new Book[capacity];
    for (int i = 0; i < size; i++)
       lib[i] = other.lib[i];
 }

 Library::~Library(){
     delete[] lib;
 }
void Library::addBook(const Book& b){
    if(size == capacity){
        grow();
    }
    lib[size] = b;
    size++;
}

void Library::grow(){
    capacity++;
    Book* temp = new Book[capacity];
    for(int i = 0; i < size; i++){
        temp[i] = lib[i];
    }
    delete [] lib;
    lib = temp;
}

int Library::getSize(){
    return size;
}
Book& Library::operator[](int i) const{
    if(i > size){
        std::cout << "Index out of bounds";
    }
    return lib[i];
}

ostream& operator<< (ostream& os, const Library& b){
    for(int i = 0; i < b.size; i++){
        os << b[i].getTitle() << " " << b[i].getAuthor() << " " << b[i].getISBN() <<endl;
    }
    return os;
}

