#include <iostream>
int main(){
	char c_str[50];
	std::cout << "Please include test of length 10 or more" << std::endl;
	std::cin.getline(c_str, 50);
	std::cout << c_str << " " << strlen(c_str) <<std::endl;
}

