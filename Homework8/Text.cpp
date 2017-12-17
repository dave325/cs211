#include "Text.h"
#include <iostream>

Text::Text(){
    name = "";
    type = "txt";
    size =  8 * charCount;
}

Text::Text(std::string n, int c){
    name = n;
    type = "txt";
    charCount = c;
    size =  8 * charCount;
}

std::string Text::getName(){
    return name;
}
std::string Text::getType(){
    return type;
}
int Text::getSize(){
    size = 8 * charCount;
    return size;
}
int Text::getCharCount(){
    return charCount;
}
void Text::displayProperties(){
 std::cout << "Name: " << name << std::endl <<
    "Type: " << type << std::endl << 
    "Size: " << size << std::endl << 
    "Character Count: " << charCount << std::endl;
}