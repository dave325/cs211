#include <iostream>
#include <cstdlib>
#include "SafeArray.h"
#include "SafeMatrix.h"

int main(){
    SafeMatrix<SafeArray<int> > s(2,3);
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
    SafeMatrix<SafeArray<std::string> > s1(2,2);
    s1[0][0] = "one";
    std::cout << s1[0][0] << std::endl;
    return 0;
}