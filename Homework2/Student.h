#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
class Student{
    private:
        std::string lastName;
        std::string firstName;
        std::string standing;
        int static id;
        int credits;
        double gpa;
        std::string dateOfBirth;
        std::string matriculationDate;
        void setStanding(int credit);
    public:
        Student();
        Student(std::string lastName, std::string firstName,int credits, double gpa, std::string dateOfBirth,std::string  matriculationDate);
        std::string getLastName();
        void setLastName(std::string name);
        std::string getFirstName();
        void setFirstName(std::string name);
        std::string getStanding();
        int getCredits();
        void setCredits(int amount);
        double getGpa();
        void setGpa(double amount);
        std::string getDateOfBirth();
        void setDateOfBirth(std::string date);
        std::string getMatriculationDate();
        void setMatriculationDate(std::string date);
        const bool operator==(const Student& s);
        const bool operator!=(const Student& s);
        const bool operator<(const Student& s);
        const bool operator>(const Student& s);
        const bool operator<=(const Student& s);
        const bool operator>=(const Student& s);
        friend const std::ostream& operator<<(std::ostream& os, const Student& s);
        friend const std::istream& operator>>(std::istream& os, const Student& s);
};

#endif