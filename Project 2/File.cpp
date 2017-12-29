#include "File.h"
#include <iostream> 

File::File(){
    name = "";
    type = "";
    size = 0;
}
std::string File::getName(){
    return name;
}
std::string File::getType(){
    return type;
}

int File::getSize(){
    return size;
}

void File::displayProperties(){
    std::cout << "Name: " << name << std::endl 
        << "Type: " << type << std::endl
        << "Size: " << size << std::endl;
}

File::~File(){
    //empty
}