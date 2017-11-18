
#include <iostream>
#include "Roster.h"
/**
 *  Name: David Dataram
 *  Class: CS211 
 *  HW #3
 */
int main(){
    Roster roster;
    roster.setCourseCode("11223");
    roster.setCourseName("Test");
    roster.setNumCredits(3);
    roster.setInstructorName("test professor");
    roster.addStudent("Man1");
    roster.addStudent("Man2");
    roster.addStudent("Man3");
    std::string man = roster.searchStudent("Man5");
    std::string man2 = roster.searchStudent("Man3");
    std::cout << roster.getCourseCode() <<  std::endl;
    std::cout << roster.getCourseName() <<  std::endl;
    std::cout << roster.getNumCredits() <<  std::endl;
    std::cout << roster.getInstructorName() <<  std::endl;
    std::cout << "Searching for man5 in students: " << man <<  std::endl;
    std::cout << "Searching for man3 in students: " << man2 <<  std::endl;
    std::cout << "Original List: "<< std::endl;
    roster.printStudents();
    roster.deleteStudent("Man1");
    roster.addStudent("Man4");
    roster.addStudent("Man5");
    std::cout << "List after deleting student man1 and adding man4 and man5: "<< std::endl;
    roster.printStudents();
    return 0;
}