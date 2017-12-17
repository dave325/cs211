#ifndef TEXT_H
#define TEXT_H
#include <string>
#include "File.h"
class Text : public File{
    private:
        std::string name;
        std::string type;
        int size;
        int charCount;
    public:  
        Text();
        Text(std::string n, int c);
        virtual std::string getName();
        virtual std::string getType();
        virtual int getSize();
        int getCharCount();
        virtual void displayProperties();
};

#endif

