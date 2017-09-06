#include <iostream>
int reverseNum(int input);
int main(){
  int input;
  std::cout << "Please enter a posiitve integer (negative will terminate program)";
  std:: cin >>input;
  while(input > 0){
    std::cout << reverseNum(input);
    std::cout << "Please enter a posiitve integer (negative will terminate program)";
    std:: cin >>input;
  }
}
int reverseNum(int input){
  int num;
  if(input < 10){
    return num;
  }
  num += input%10;
  return reverseNum(input/10);
}
