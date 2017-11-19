#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include "Date.h"
class Student{
    private:
        std::string lastName;
        std::string firstName;
        std::string standing;
        int id;
        int credits;
        double gpa;
        Date dateOfBirth;
        Date matriculationDate;
        void setStanding(int credit);
    public:
        static int idCount;
        Student();
        Student(std::string lastName, std::string firstName,int credits, double gpa, Date dateOfBirth,Date matriculationDate);
        std::string getLastName();
        void setLastName(std::string name);
        std::string getFirstName();
        void setFirstName(std::string name);
        std::string getStanding();
        int getId();
        int getCredits();
        void setCredits(int amount);
        double getGpa();
        void setGpa(double amount);
        Date getDateOfBirth();
        void setDateOfBirth(Date date);
        Date getMatriculationDate();
        void setMatriculationDate(Date date);
        const bool operator==(const Student& s);
        const bool operator!=(const Student& s);
        const bool operator<(const Student& s);
        const bool operator>(const Student& s);
        const bool operator<=(const Student& s);
        const bool operator>=(const Student& s);
        friend const std::ostream& operator<<(std::ostream& os, Student& s);
        friend const std::istream& operator>>(std::istream& os, Student& s);
};

#endif