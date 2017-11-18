#include <iostream>
int qa(int arr[]);
int qb(int arr[]);
int qc(int arr[]);
int main(){
	int a[11] = {10,15, 21, 3, 92, 48, 29, 12, 46, 34, 12};
	std::cout << qa(a) << std::endl;
	std::cout << qb(a) << std::endl;
	std::cout << qc(a) << std::endl;	
}
int qa(int arr[]){
	int sum = 0;
	for(int i = 1; i < arr[0];i++){
		if(i % 2 == 0){
			sum += arr[i];
		}
	}
	return sum;
}
int qb(int arr[]){
	int sum = 0;
	for(int i = 1; i < arr[0];i++){
		if(i % 2 == 0){
			if(arr[i] % 2 ==0){
				sum += arr[i];
			}
		}
	}
	return sum;
}
int qc(int arr[]){
	int sum = 0;
	for(int i = 1; i < arr[0];i++){
		if(i % 2 == 1){
			if(arr[i] % 2 ==0){
				sum += arr[i];
			}
		}
	}
	return sum;
}

