// David Dataram CS211 HW#2
#include <string>
#include <iostream>
#include "Student.h"
#include "Date.h"

// Set the standing for student each time credits is set/updated
void Student::setStanding(int credit){
    if(credits < 30){
        this->standing = "freshman";
    }
    if(credits < 60 && credits >= 30){
        this->standing = "sophmore";
    }
    if(credits < 90 && credits >= 60){
        this->standing = "junior";
    }
    if(credits <= 120 && credits >= 90){
        this->standing = "senior";
    }
}
// Default Constructor
Student::Student(){
    this->lastName = "";
    this->firstName = "";
    setCredits(10);
    this->gpa = 0;
    this->dateOfBirth = Date();
    this->matriculationDate = Date();
    this->id = idCount++;
}
// Constructor if all values are given
Student::Student(std::string lastName, std::string firstName,int credits, double gpa, Date dateOfBirth,Date matriculationDate){
    this->lastName = lastName;
    this->firstName = firstName;
    setCredits(credits);
    this->gpa = gpa;
    this->dateOfBirth = dateOfBirth;
    this->matriculationDate = matriculationDate;
    this->id = idCount++;
}  

// returns lastName variable
std::string Student::getLastName(){
    return lastName;
}

// sets lastName variable
void Student::setLastName(std::string name){
    this->lastName = name;
}

// returns firstName variable
std::string Student::getFirstName(){
    return firstName;
}

// sets lastName variable
void Student::setFirstName(std::string name){
    this->firstName = name;
}

int Student::getId(){
    return id;
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
    this->credits = amount;
    setStanding(this->credits);
}

// Returns the gpa
double Student::getGpa(){
    return gpa;
}

// Sets the gpa
void Student::setGpa(double amount){
    this->gpa = amount;
}

// Returns date of birth
Date Student::getDateOfBirth(){
    return dateOfBirth;
}

// Sets date of birth
void Student::setDateOfBirth(Date date){
    this->dateOfBirth = date;
}

// Returns matriculationDate
Date Student::getMatriculationDate(){
    return matriculationDate;
}

// Sets matriculationDate
void Student::setMatriculationDate(Date date){
    this->matriculationDate = date;
}

// Prints out all student information
const std::ostream& operator<<(std::ostream &os, Student& s){
    os << "Last Name: " << s.getLastName() <<std::endl;
    os << "First Name: " << s.getFirstName() <<std::endl;
    os << "Credits: " << s.getCredits() <<std::endl;
    os << "Standing: " << s.getStanding() <<std::endl;
    os << "GPA: " << s.getGpa() <<std::endl;
    os << "DOB: " << s.dateOfBirth;
    os << "Matriculation Date: " << s.matriculationDate;
    os << "Id: " << s.getId() <<std::endl;
    return os;
}

// Sets all student information
const std::istream& operator>>(std::istream &is, Student& s){
    std::string tempString; int tempInt; double tempDouble; Date tempDate;
    std::cout << "Last Name: (original " << s.getLastName() << ") " << std::endl;
    is >> tempString; s.setLastName(tempString);
    std::cout << "First Name: (original " << s.getFirstName() << ") "<< std::endl;
    is >> tempString; s.setFirstName(tempString);
    std::cout << "Credits: (original " << s.getCredits() << ") "<< std::endl;
    is >> tempInt; s.setCredits(tempInt);
    std::cout << "GPA: (Original " << s.getGpa() << ")" << std::endl;
    is >> tempDouble; s.setGpa(tempDouble);
    std::cout << "DOB: original " << s.dateOfBirth;
    is >> tempDate; s.setDateOfBirth(tempDate);
    std::cout << "Matriculation Date: original " << s.matriculationDate;
    is >> tempDate; s.setMatriculationDate(tempDate);
    return is;
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
    if(this->firstName < s.firstName && this->lastName < this->firstName && this->id - s.id < 0){
        return true;
    }else{
        return false;
    }
}

const bool Student::operator>(const Student& s){
    if(this->firstName > s.firstName && this->lastName > this->firstName && this->id - s.id > 0){
        return true;
    }else{
        return false;
    }
}

const bool Student::operator<=(const Student& s){
    if(this->firstName <= s.firstName && this->lastName <= this->firstName && this->id - s.id <= 0){
        return true;
    }else{
        return false;
    }
}

const bool Student::operator>=(const Student& s){
    if(this->firstName >= s.firstName && this->lastName >= this->firstName && this->id - s.id >= 0){
        return true;
    }else{
        return false;
    }
}