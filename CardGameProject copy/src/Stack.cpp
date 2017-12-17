#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Card.h"

template <typename T>
class Stack{
    private:
        T** stack;
        int capacity;
        bool isEmpty() const;
        bool isFull() const;
        void grow();
        void shrink();
    public:
        Stack();
        Stack(const Stack& other);
        ~Stack();
        int getCapacity();
        int getSize();
        void setSize(int s);
        void setCapacity(int c);
        void push(T* c);
        T* pop();
        T* peek()const;
        Stack& operator=(const Stack& s);
        friend const std::ostream& operator<<(std::ostream& os, Stack<T>& s){
            while (!s.isEmpty())
            {
                T* c = s.pop();
                os << *c;
                delete c;
            }
            return os;
        }
        friend const std::istream& operator>>(std::istream& is, Stack<T>& s);
};


template <typename T>
Stack<T>::Stack(){
    capacity = 0;
    stack = NULL;
}

template <typename T>
Stack<T>::Stack(const Stack& other){
    capacity = other.capacity;
    stack = new T*[capacity];
    for(int i = 0; i < capacity; i++){
        stack[i] = new T(*(other.stack[i]));
    }
}

template <typename T>
Stack<T>::~Stack(){
    for(int i = 0; i < capacity; i++){
         delete stack[i];
    }
    delete[] stack;
}

template <typename T>

int Stack<T>::getCapacity(){
    return capacity;
}

template <typename T>
void Stack<T>::push(T* c){
    grow();
    stack[capacity - 1] = c;
}

template <typename T>

T* Stack<T>::pop(){
    
    if(isEmpty()){
        return NULL;
    }
    T* temp = stack[capacity - 1];
    shrink();
    return temp; 
}

template <typename T>
bool Stack<T>::isEmpty()const {
    return capacity == 0;
}


template <typename T>
T* Stack<T>::peek() const{ 
    if (isEmpty())
    {
        return NULL;
    }
   return stack[capacity - 1];
}

template <typename T>
void Stack<T>::grow(){
    capacity++;
    T** temp = new T*[capacity];
    for(int i = 0; i < capacity - 1; i++){
        temp[i] = stack[i];
    }
    delete[] stack;
    stack = temp;
}

template <typename T>
void Stack<T>::shrink()
{
    if (isEmpty())
    {
        return;
    }
    capacity--;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& s){
    if (this == &s)
      return *this;
    capacity = s.capacity;
    delete[] stack;
    stack = new T*[capacity];
    for(int i = 0; i < capacity; i++){
        stack[i] = new T(*(s.stack[i]));
    }
    return *this;
}


template <typename T>
const std::istream& operator>>(std::istream& is, Stack<T>& s){
    for(int i = 0; i < s.capacity; i++){
        is >> *(s.stack[i]);
    }   
    return is;
}
#endif