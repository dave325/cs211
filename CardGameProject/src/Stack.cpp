#include <string>
#include <iostream>
#include "Card.h"
#include "Stack.h"

Stack::Stack(){
    capacity = 0;
    stack = NULL;
}

Stack::Stack(const Stack& other){
    capacity = other.capacity;
    stack = new Card*[capacity];
    for(int i = 0; i < capacity; i++){
        stack[i] = new Card(*(other.stack[i]));
    }
}

Stack::~Stack(){
    for(int i = 0; i < capacity; i++){
         delete stack[i];
    }
    delete[] stack;
}

int Stack::getCapacity(){
    return capacity;
}

void Stack::push(Card* c){
    grow();
    stack[capacity - 1] = c;
}

Card* Stack::pop(){
    
    if(isEmpty()){
        return NULL;
    }
    Card* temp = stack[capacity - 1];
    shrink();
    return temp; 
}

bool Stack::isEmpty()const {
    return capacity == 0;
}


Card* Stack::peek() const{ 
    if (isEmpty())
    {
        return NULL;
    }
   return stack[capacity - 1];
}

void Stack::grow(){
    capacity++;
    Card** temp = new Card*[capacity];
    for(int i = 0; i < capacity - 1; i++){
        temp[i] = stack[i];
    }
    delete[] stack;
    stack = temp;
}

void Stack::shrink()
{
    if (isEmpty())
    {
        return;
    }
    capacity--;
}

Stack& Stack::operator=(const Stack& s){
    if (this == &s)
      return *this;
    capacity = s.capacity;
    delete[] stack;
    stack = new Card*[capacity];
    for(int i = 0; i < capacity; i++){
        stack[i] = new Card(*(s.stack[i]));
    }
    return *this;
}

const std::ostream& operator<<(std::ostream& os, Stack& s){
    while (!s.isEmpty())
    {
        Card* c = s.pop();
        os << *c;
        delete c;
    }
    return os;
}

const std::istream& operator>>(std::istream& is, Stack& s){
    for(int i = 0; i < s.capacity; i++){
        is >> *(s.stack[i]);
    }   
    return is;
}