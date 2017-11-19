#include "Student.h"
#include <iostream>
int Student::idCount = 0;
int main(){
    Student s1("Dataram", "David", 90,3.5, "3/25/1994", "9/2017");
    Student s2("Dataram", "David", 90,3.5, "3/25/1994", "9/2017");
    Student s3;
    //std::cin >> s3;
    std::cout << s1;   
    std::cout << s2;
    std::cout << (s1 >= s2) << std::endl; 
    //std::cout << s3;   
}
