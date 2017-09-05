#include <iostream>
#include <cmath>
void isPrime(int num);
int main() {
  int num;
  std::cout << "Please enter a positive integer" << std::endl;
  std::cin >> num;
  isPrime(num);
  return 0;
}
void isPrime(int num){
  bool isPrime;
  for(int i = 1; i <= num; i++){
    isPrime = true;
    for(int j = 2; j <= i/2; j++){
      if(i % j == 0){
        isPrime = false;
        break;
      }
    }
    if(isPrime){
      std::cout << i << std::endl;
    }
  }
}
