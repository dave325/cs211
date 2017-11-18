#include <string>
#include <iostream>
#include "Roster.h"
/**
 *  Name: David Dataram
 *  Class: CS211 
 *  HW #3
 */
// Retrieve Course Number
std::string Roster::getCourseName() const{
    return course_name;
}
// Sets course number
void Roster::setCourseName(std::string courseName){
    course_name = courseName;
}
// Retrieves Course Code
std::string Roster::getCourseCode() const{
    return course_code;
}

// Sets Course code
void Roster::setCourseCode(std::string courseCode){
    course_code = courseCode;
}

// Retrieves num_credits
int Roster::getNumCredits() const{
    return num_credits;
}

// Sets num_credits
void Roster::setNumCredits(int num){
    num_credits = num;
}

// Retrieves instructor name
std::string Roster::getInstructorName() const{
    return instructor_name;
}

// Sets instructor name
void Roster::setInstructorName(std::string name){
    instructor_name = name;
}

// Adds Student to array
void Roster::addStudent(std::string student){
    int size = 10;
    for(int i= 0; i< size; i++){
        // Student is set, then break loop 
        if(students[i] == ""){
            students[i] = student;
            break;
        }else{
            continue;
        }
    }
}

// Deletes student
void Roster::deleteStudent(std::string student){
    int size = MAX_CAPACITY;
    for(int i= 0; i< size; i++){
        // Finds student in loop and deletes them
        if(students[i] == student){
            students[i] = "";
        }
    }
}

// Searches for student
std::string Roster::searchStudent(std::string student){
    int size = MAX_CAPACITY;
    for(int i= 0; i< size; i++){
        // If student is found, then return student
        if(students[i] == student){
            return students[i];
        }
    }
    // If no student is found the return
     return "Student not found";
}

// Prints out all students
void Roster::printStudents(){
    for(int i = 0; i < MAX_CAPACITY; i++){
        // If no value is found for student then continue the loop
        if(students[i] == ""){
            continue;
        }
        // Print out student if value is found
        std::cout << "Student " << i << ": " <<students[i] << std::endl;
    }
}