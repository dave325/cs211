#include <iostream>
int main(){
	int n[10];
	int i = 0;
	int sum = 0;
	std::cout << "Please intput 10 integers" <<std::endl;
	while(std::cin.peek() != EOF && i < 10){
		std::cin >> n[i];
		sum += n[i];
		i++;
	}
	int avg = sum/10;
	for(int j = 0; j < 10; j++){
		if ( n[j] >= avg){
			std::cout << n[j] << std::endl;
		}
	} 
}
