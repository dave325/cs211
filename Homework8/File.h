#ifndef FILE_H
#define FILE_H
#include <string>

class File {
    private:
        std::string name;
        std::string type;
        int size;
    public:  
        File();
        virtual std::string getName();
        virtual std::string getType();
        virtual int getSize();
        virtual void displayProperties();
        virtual ~File();
};

#endif

