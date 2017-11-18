// David Dataram CS211 HW#2
#include <string>
#include <iostream>
class Student{
    private:
        // Set instance variables
        std::string lastName;
        std::string firstName;
        std::string standing;
        int credits;
        double gpa;
        std::string dateOfBirth;
        std::string  matriculationDate;
        // Set the standing for student each time credits is set/updated
        void setStanding(int credit){
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
    public:
        // Default Constructor
        Student(){
            setLastName("Test");
            setFirstName("Test");
            setCredits(10);
            setGpa(30);
            setDateOfBirth("Test");
            setMatriculationDate("Test");
        }
        // Constructor if all values are given
        Student(std::string lastName, std::string firstName,int credits, double gpa, std::string dateOfBirth,std::string  matriculationDate){
           setLastName(lastName);
           setFirstName(firstName);
           setCredits(credits);
           setGpa(gpa);
           setDateOfBirth(dateOfBirth);
           setMatriculationDate(matriculationDate);
        }  
        // returns lastName variable
        std::string getLastName(){
            return lastName;
        }
        // sets lastName variable
        void setLastName(std::string name){
            lastName = name;
        }
        // returns firstName variable
        std::string getFirstName(){
            return firstName;
        }
        // sets lastName variable
        void setFirstName(std::string name){
            firstName = name;
        }
        // Returns the standing
        std::string getStanding(){
            return standing;
        }
        // Returns the credits
        int getCredits(){
            return credits;
        }
        // sets the credits and standing 
        void setCredits(int amount){
            credits = amount;
            setStanding(credits);
        }
        // Returns the gpa
        double getGpa(){
            return gpa;
        }
        // Sets the gpa
        void setGpa(double amount){
            gpa = amount;
        }
        // Returns date of birth
        std::string getDateOfBirth(){
            return dateOfBirth;
        }
        // Sets date of birth
        void setDateOfBirth(std::string date){
            dateOfBirth = date;
        }
        // Returns matriculationDate
        std::string getMatriculationDate(){
            return matriculationDate;
        }
        // Sets matriculationDate
        void setMatriculationDate(std::string date){
            matriculationDate = date;
        }
        // Prints out all student information
        void printStudentDetails(){
            std::cout << "Last Name: " << lastName <<std::endl;
            std::cout << "First Name: " << firstName <<std::endl;
            std::cout << "Credits: " << credits <<std::endl;
            std::cout << "Standing: " << standing <<std::endl;
            std::cout << "GPA: " << gpa <<std::endl;
            std::cout << "DOB: " << dateOfBirth <<std::endl;
            std::cout << "Matriculation Date: " << matriculationDate <<std::endl;
        }
        // Sets all student information
        void setStudentDetails(){
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
};
int main(){
    Student s1("Dataram", "David", 90,3.5, "3/25/1994", "9/2017");
    s1.setStudentDetails();
    s1.printStudentDetails();
}
