#include "Book.h"

#include <string>
using namespace std;

Book::Book(){
    title = "";
    author = "";
    isbn = 0;
}

Book::Book(string t, string a, int i){
    title = t;
    author = a;
    isbn = i;
}

const string Book::getTitle() const{
    return title;
}

const string Book::getAuthor() const{
    return author;
}

const int Book::getISBN() const{
    return isbn;
}