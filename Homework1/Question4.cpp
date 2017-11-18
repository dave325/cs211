#include <iostream>
int reverseNum(int input);
int main(){
  int input;
  std::cout << "Please enter a posiitve integer (negative will terminate program)";
  std:: cin >>input;
  while(input > 0){
    std::cout << reverseNum(input);
    std::cout << "Please enter a posiitve integer (negative will terminate program)";
    std::cin >>input;
  }
}
int reverseNum(int input){
  int rev = 0, rem;
  while(input!=0)
	{
		rem=input%10;
		rev=rev*10+rem;
		input=input/10;
	}
  return rev;
}
