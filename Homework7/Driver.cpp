#include <iostream>
#include <cstdlib>
#include "SafeArray.h"
#include "SafeMatrix.h"
/**
 *  Name: David Dataramm
 * Class: CS211 MW 7:30pm - 8:20PM
 */ 

int main(){
    SafeMatrix<int> s(2,6);
    for(int i = 0; i < s.length(); i++){
        for(int j = 0; j < s[0].length(); j++){
            s[i][j] = (i *j) + (5 + j);
        }
    }
    for(int i = 0; i < s.length(); i++){
        for(int j = 0; j < s[0].length(); j++){
            std::cout << s[i][j] << std::endl;
        }
    }
    SafeMatrix<std::string> s1(5,2);
    s1[0][0] = "one";
    s1[1][0] = "two";
    for(int i = 0; i < s1.length(); i++){
        for(int j = 0; j < s1[0].length(); j++){
            s1[i][j] =  'A'+ (i + j + 5);
        }
    }
    for(int i = 0; i < s1.length(); i++){
        for(int j = 0; j < s1[0].length(); j++){
            std::cout << s1[i][j] << std::endl;
        }
    }
    return 0;
}