#include <string>
#include <iostream>
#include "Tokenizer.h"
using namespace std;

Tokenizer::Tokenizer(string s[], int n){
    size = n;
    point = 0;
    str = new string[size];
    for (int i = 0; i < size; i++)
        str[i] = s[i];
}

string Tokenizer::getNext(){
    return str[point];
}

bool Tokenizer::isEmpty(){
    return size == 0;
}

bool Tokenizer::hasMoreWords(){
    return size > 0;
}

void Tokenizer::resetPointer(){
    point = 0;
}
string Tokenizer::operator++(int){
    string s = str[point];
    point++;
    return s; 
}

