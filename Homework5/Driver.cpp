#include "Student.h"
#include "Roster.h"
#include "Date.h"
#include <iostream>
#include <string>
int Student::idCount = 0;
int main(){
    Student s1("Dataram", "David", 90,3.5, Date(3,3,2017), Date(3,3,2017));
    Student s2("Dataram", "David11", 90,3.5, Date(3,3,2017), Date(3,3,2017));
    Student s3("Dataram", "David11", 90,3.5, Date(3,3,2017), Date(3,3,2017));
    Student s4("Dataram", "David11", 90,3.5, Date(3,3,2017), Date(3,3,2017));
    Roster r;
    r.addStudent(s4);
    r.addStudent(s3);
    r.addStudent(s2);
    r.addStudent(s1);
    std::cout << r;
}