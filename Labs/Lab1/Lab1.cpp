#include <string>
#include <iostream>
int main(){
	char c[50];
	std::cout << "Please include text the length of 10 or more" << std::endl;
	std::cin.getline(c, 49);
	std::cout << c << " Length of " << strlen(c) << std::endl;
	
}
