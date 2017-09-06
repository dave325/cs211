#include <iostream>
void printPerfNum(int num);
int main(){
	int num;
  std::cout << "Please enter a positive integer" << std::endl;
  std::cin >> num;
  printPerfNum(num);
	return 0;
}
void printPerfNum(int num){
	int isPerfect;
	for(int i = 1; i <= num; i++){
    isPerfect = 0;
    for(int j = 1; j <= i/2; j++){
			if(i % j == 0){
				isPerfect += j;
			}
    }
    if(isPerfect == i){
      std::cout << i << std::endl;
    }
  }
}
