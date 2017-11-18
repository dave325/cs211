#include <iostream>
int main(){
	int x[10];
	int i = 0;
	while(i < 10){
		std::cout << "Please enter more integers" << std::endl;
		std::cin >> x[i];
		i++;
	}
	std::cout << "Below are numbers not divisible by 3 and 4" <<std::endl;
	for(int j = 0; j < 10; j++){
		int num = x[j] * x[j];
		if(num % 3 == 0 || num % 4 == 0){
			continue;
		}else{
			std::cout << x[j] << std::endl;
		}
	}
}
