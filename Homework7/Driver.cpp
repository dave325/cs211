#include <iostream>
#include <cstdlib>
#include "SafeArray.h"
#include "SafeMatrix.h"
/**
 *  Name: David Dataramm
 * Class: CS211 MW 7:30pm - 8:20PM
 */ 

int main(){
    SafeMatrix<int> s(2,3);
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
    SafeMatrix<std::string> s1(2,2);
    s1[0][0] = "one";
    s1[1][0] = "two";
    std::cout << s1[0][0] << std::endl;
    std::cout << s1[1][0] << std::endl;
    return 0;
}