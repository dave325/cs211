#include <string>
#include "Student.h"
#ifndef ROSTER_H
#define ROSTER_H
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
        Student* students;
        int size;
        void sortStudents();
        void grow();
        void shrink();
    public:
        Roster();
        Roster(const Roster& other);
        Roster& operator=(const Roster& other);
        ~Roster();
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
        Student operator[](int idx) const;
        friend const std::ostream& operator<<(std::ostream& os, Roster& r);
        friend const std::istream& operator>>(std::istream& is, Roster& r);

};
#endif 
