#include <string>

using namespace std;
#ifndef TOKENIZER_H
#define TOKENIZER_H

class Tokenizer{
    private:
        string* str;
        int point;
        int size;
    public:
        Tokenizer(string s[], int n);
        string getNext();
        string operator++(int);
        bool isEmpty();
        bool hasMoreWords();
        void resetPointer();
};

#endif