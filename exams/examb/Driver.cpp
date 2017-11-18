#include <iostream> 
#include <string>

#include "Book.h"
#include "Library.h"

int main(){
    Library l(5);
    Book b("test", "tester", 1);
    l.addBook(b);
    Book b1("test", "testr", 1);
    l.addBook(b1);
    std::cout << l << std::endl;
}