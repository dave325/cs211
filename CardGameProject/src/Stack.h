#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Card.h"

class Stack{
    private:
        Card** stack;
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
        void push(Card* c);
        Card* pop();
        Card* peek()const;
        Stack& operator=(const Stack& s);
        friend const std::ostream& operator<<(std::ostream& os, Stack& s);
        friend const std::istream& operator>>(std::istream& is, Stack& s);
};

#endif