#include <iostream>
int main(){
	int n;
	std::cout << "Please enter an integer" << std::endl;
	std::cin >> n;
	for(int i =1; i <= n/2; i++){
		if (n % i == 0){
			std::cout << i << std::endl;	
		}
	} 
}
