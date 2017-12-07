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
        friend const std::ostream& operator<<(std::ostream& os, Stack& s);
        friend const std::istream& operator>>(std::istream& is, Stack& s);
};

#endif