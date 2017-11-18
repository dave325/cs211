#include <string>
#include "Card.h"

std::string Card::getSuite(){
    return suite;
}

void Card::setSuite(std::string value){
    suite = value;
}

std::string Card::getValue(){
    return value;
}

void Card::setValue(std::string name){
    value = name;
}