// David Dataram CS211 HW#2
#include <string>
#include <iostream>
#include "Student.h"
// Set the standing for student each time credits is set/updated
void Student::setStanding(int credit){
    if(credits < 30){
        standing = "freshman";
    }
    if(credits < 60 && credits >= 30){
        standing = "sophmore";
    }
    if(credits < 90 && credits >= 60){
        standing = "junior";
    }
    if(credits <= 120 && credits >= 90){
        standing = "senior";
    }
}
// Default Constructor
Student::Student(){
    lastName = "";
    firstName = "";
    setCredits(10);
    gpa = 0;
    dateOfBirth = "";
    matriculationDate = "";
    id++;
}
// Constructor if all values are given
Student::Student(std::string lastName, std::string firstName,int credits, double gpa, std::string dateOfBirth,std::string  matriculationDate){
    this->lastName = lastName;
    this->firstName = firstName;
    setCredits(credits);
    this->gpa = gpa;
    this->dateOfBirth = dateOfBirth;
    this->matriculationDate = matriculationDate;
    id++;
}  

// returns lastName variable
std::string Student::getLastName(){
    return lastName;
}

// sets lastName variable
void Student::setLastName(std::string name){
    lastName = name;
}

// returns firstName variable
std::string Student::getFirstName(){
    return firstName;
}

// sets lastName variable
void Student::setFirstName(std::string name){
    firstName = name;
}

// Returns the standing
std::string Student::getStanding(){
    return standing;
}

// Returns the credits
int Student::getCredits(){
    return credits;
}

// sets the credits and standing 
void Student::setCredits(int amount){
    credits = amount;
    setStanding(credits);
}

// Returns the gpa
double Student::getGpa(){
    return gpa;
}

// Sets the gpa
void Student::setGpa(double amount){
    gpa = amount;
}

// Returns date of birth
std::string Student::getDateOfBirth(){
    return dateOfBirth;
}

// Sets date of birth
void Student::setDateOfBirth(std::string date){
    dateOfBirth = date;
}

// Returns matriculationDate
std::string Student::getMatriculationDate(){
    return matriculationDate;
}

// Sets matriculationDate
void Student::setMatriculationDate(std::string date){
    matriculationDate = date;
}

// Prints out all student information
const std::ostream& operator<<(std::ostream& os, const Student& s){
    os << "Last Name: " << lastName <<std::endl;
    os << "First Name: " << firstName <<std::endl;
    os << "Credits: " << credits <<std::endl;
    os << "Standing: " << standing <<std::endl;
    os << "GPA: " << gpa <<std::endl;
    os << "DOB: " << dateOfBirth <<std::endl;
    os << "Matriculation Date: " << matriculationDate <<std::endl;
    return os;
}

// Sets all student information
const std::istream& operator>>(std::istream& is, const Student& s){
    std::string tempString; int tempInt; double tempDouble;
    std::cout << "Last Name: (original " << getLastName() << ") " << std::endl;
    std::cin >> tempString; setLastName(tempString);
    std::cout << "First Name: (original " << getFirstName() << ") "<< std::endl;
    std::cin >> tempString; setFirstName(tempString);
    std::cout << "Credits: (original " << getCredits() << ") "<< std::endl;
    std::cin >> tempInt; setCredits(tempInt);
    std::cout << "GPA: (Original " << getGpa() << ")" << std::endl;
    std::cin >> tempDouble; setGpa(tempDouble);
    std::cout << "DOB: (original " << getDateOfBirth() << ") " << std::endl;
    std::cin >> tempString; setDateOfBirth(tempString);
    std::cout << "Matriculation Date: (original " << getMatriculationDate() << ") " << std::endl;
    std::cin >> tempString; setMatriculationDate(tempString);
}

const bool Student::operator==(const Student& s){
    if(this->firstName == s.firstName && this->lastName == s.lastName && this->id == s.id){
        return true;
    }
    return false;
}

const bool Student::operator!=(const Student& s){
    if(this->firstName != s.firstName || this->lastName != s.lastName || this->id != s.id){
        return true;
    }
    return false;
}

const bool Student::operator<(const Student& s){
    
}

const bool Student::operator>(const Student& s){

}

const bool Student::operator<=(const Student& s){

}

const bool Student::operator>=(const Student& s){

}