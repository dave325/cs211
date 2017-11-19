#include <string>
#include <iostream>
#include "Roster.h"
#include "Student.h"
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
void Roster::addStudent(const Student& student){
    for(int i= 0; i< MAX_CAPACITY; i++){
        // Student is set, then break loop 
        if(students[i].getFirstName() == ""){
            students[i] = student;
            sortStudents();
            break;
        }
    }
}

// Deletes student
void Roster::deleteStudent(const Student& student){
    int size = MAX_CAPACITY;
    for(int i= 0; i< size; i++){
        // Finds student in loop and deletes them
        if(students[i] == student){
            for(int j = i; j < MAX_CAPACITY; j++){
                students[i] = students[i+1];
            }
            break;
        }
    }
}


// Searches for student
Student Roster::searchStudent(const Student student){
    int size = MAX_CAPACITY;
    for(int i= 0; i< size; i++){
        // If student is found, then return student
        if(students[i] == student){
            return students[i];
        }
    }
    Student null;
    // If no student is found the return
     return null;
}

void Roster::sortStudents(){
   int i, j;
   Student key;
   for (i = 1; i < MAX_CAPACITY; i++)
   {
       key = students[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && students[j] > key)
       {
           students[j+1] = students[j];
           j = j-1;
       }
       students[j+1] = key;
   }
}

// Prints out all students
const std::ostream& operator<<(std::ostream& os, Roster& r){
    for(int i = 0; i < MAX_CAPACITY; i++){
        if(r.students[i].getLastName() == ""){
            break;
        }
        // Print out student if value is found
        os << "Student " << i << ": " << std::endl << r.students[i];
    }
    return os;
}

const std::istream& operator>>(std::istream& is, Roster& r){
    for (int i = 0; i < MAX_CAPACITY; i++){
        if(r.students[i].getLastName() != ""){
            continue;
        }
        std::string ans;
        is >> r.students[i];
        std::cout << "Do you want to add more students. Y for yes, N for no" << std::endl;
        std::cin >> ans;
        transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
        if(ans != "y" ){
            break;
        }
    }
    return is;
}



