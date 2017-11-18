#include <iostream>
#include <cstdlib>
int main(){
	int arr[20];
	int j = 0;
	for(int i = 0; i < 20; i++){
		int ranNum = rand() % 20 + 1;
		while(j <= i){
			if(arr[j] == ranNum){
				j = 0;
				ranNum = rand() % 20 +1;
			}
			else if (j == i){
				arr[j] = ranNum;
				break;
			}else{
				j++;
			}
		}
		j = 0;	
		std::cout << arr[i] << std::endl;
	}
}
