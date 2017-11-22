#include <iostream>
#include "Date.h"
#include "Student.h"
#include "Roster.h"
int Student::idCount = 0;
int main(){
    Roster r;
    std::cin >> r;
    std::cout << r;
    return 0;
}