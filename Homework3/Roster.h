#include <string>
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
        std::string students[MAX_CAPACITY];
    public:
        std::string getCourseName() const;
        void setCourseName(std::string courseName);
        std::string getCourseCode() const;
        void setCourseCode(std::string courseCode);
        int getNumCredits() const;
        void setNumCredits(int num);
        std::string getInstructorName() const;
        void setInstructorName(std::string name);
        void addStudent(std::string student);
        void deleteStudent(std::string student);
        std::string searchStudent(std::string student);
        void printStudents();
};
#endif 
