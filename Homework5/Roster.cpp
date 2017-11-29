#include <string>
#include <iostream>
#include "Roster.h"
#include "Student.h"
int Student::idCount = 0;

Roster::Roster(){
    course_name = "";
    course_code = "";
    num_credits = 0;
    instructor_name = "";
    size = 1;
    students = new Student[size];
}

 Roster::Roster(const Roster& other){
    course_name = other.course_name;
    course_code = other.course_code;
    num_credits = other.num_credits;
    instructor_name = other.instructor_name;
    size = other.size;
    delete students;
    students = other.students;
 }

void Roster::grow(){
    Student* temp = new Student[size++];
    for(int i =0; i < size; i++){
        temp[i] = students[i];
    }
    delete [] students;
    students = temp;
}

void Roster::shrink(){
    Student* temp = new Student[size--];
    for(int i =0; i < size; i++){
        temp[i] = students[i];
    }
    delete[] students;
    students = temp;
}

Roster::~Roster(){
    delete[] students;
}
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
    grow();
    students[size] = student;
}

// Deletes student
void Roster::deleteStudent(const Student& student){
    for(int i= 0; i< size; i++){
        // Finds student in loop and deletes them
        if(students[i] == student){
            for(int j = i; j < size; j++){
                students[i] = students[i+1];
            }
            shrink();
            break;
        }
    }
}


// Searches for student
Student Roster::searchStudent(const Student student){
    for(int i= 0; i< size; i++){
        // If student is found, then return student
        if(students[i] == student){
            return students[i];
        }
    }
    // If no student is found the return
    std::cout << "Index does not exist" << std::endl;
    exit(0);
}

void Roster::sortStudents(){
   int i, j;
   Student key;
   for (i = 1; i < size; i++)
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

Student& Roster::operator[](int idx) const{
    if(idx > size || idx < 0){
        std::cout << "Index does not exist" << std::endl;
        exit(0);
    }
    return students[idx];
}

// Prints out all students
const std::ostream& operator<<(std::ostream& os, Roster& r){
    for(int i = 0; i < r.size; i++){
        if(r.students[i].getLastName() == ""){
            break;
        }
        // Print out student if value is found
        os << "Student " << i << ": " << std::endl << r.students[i];
    }
    return os;
}

const std::istream& operator>>(std::istream& is, Roster& r){
    std::string ans;
    int i = 0;
    do{
        is >> r.students[i];
        std::cout << "Do you want to add more students. Y for yes, N for no" << std::endl;
        std::cin >> ans;
        // Retrive the lowercase value
        transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
        r.grow();
        i++;
    }while(ans == "y");
    return is;
}