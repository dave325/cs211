#include <iostream>
int main(){
	int num;
	int sum = 0;
	std::cout << "Enter number"<<std::endl;
	std::cin >> num;
	for(int i = 1; i <= num; i++){
		sum += i;
	}
	std::cout << sum << std::endl;
}
