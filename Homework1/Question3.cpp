#include <iostream>
void printLeapYears(int min, int max);
int main(){
  int min, max;
  std::cout << "Please enter two years to find all leap years." << std::endl;
  std::cin >> min >> max;
  printLeapYears(min, max);
  return 0;
}
void printLeapYears(int min, int max){
  int count = 1;
  for(int i = min; i <= max; i++){
    if(i % 100 == 0 || i % 4 == 0){
      std::cout << i << " ";
      if(count % 5 == 0){
        std::cout << std::endl;
        count = 0;
      }
      count++;
    }
  }
}
