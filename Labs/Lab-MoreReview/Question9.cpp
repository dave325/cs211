#include <iostream>
#include <cstdlib>
int main(){
	int arr[10][10];
	int max =0;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			arr[i][j] = rand() % 999 + 100;
			if(j == 0){
				max += arr[j][i];
			}
		}
	}
	for(int k = 0; k < 10; k++){
		int sumCol = 0;
		for(int l = 0; l < 10; l++){
			sumCol += arr[l][k];		
		}
		std::cout << "Column " << k << ": " << sumCol << std::endl;
		if(sumCol > max){
			max = sumCol;
		}
	}
	std::cout << "Max Column is:" << max << std::endl;
}
