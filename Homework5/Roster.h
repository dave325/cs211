#include <string>
#include "Student.h"
#ifndef HEADER_H
#define HEADER_H
// Declares MAX_CAPACITY
#define MAX_CAPACITY 10
/**
 *  Name: David Dataram
 *  Class: CS211 
 *  HW #3
 */
class Roster{
    private:
        std::string course_name;
        std::string course_code;
        int num_credits;
        std::string instructor_name;
        Student students[MAX_CAPACITY];
        void sortStudents();
    public:
        std::string getCourseName() const;
        void setCourseName(std::string courseName);
        std::string getCourseCode() const;
        void setCourseCode(std::string courseCode);
        int getNumCredits() const;
        void setNumCredits(int num);
        std::string getInstructorName() const;
        void setInstructorName(std::string name);
        void addStudent(const Student& student);
        void deleteStudent(const Student& student);
        Student searchStudent(const Student student);
        void printStudents();

        // Have to implement
        friend const std::ostream& operator<<(std::ostream& os, Roster& r);
        friend const std::istream& operator>>(std::istream& is, const Roster& r);

};
#endif 
