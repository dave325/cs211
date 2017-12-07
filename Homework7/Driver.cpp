#include <iostream>
#include <cstdlib>
#include "SafeArray.h"
#include "SafeMatrix.h"

int main(){
    SafeMatrix<int> s{2};
    std::cout << s.length() << std::endl;
    return 0;
}