#include <iostream>
#include <fstream>
#include <cstdlib>
int main(){
	int arr[20][10];
    std::ofstream file;
    file.open("lab2.txt", std::fstream::out | std::ios::trunc);
    if (!file.is_open() ) {
        std::cerr << "File failed to open." << std::endl;
        return 0; 
    }
    for(int i = 0; i < 20; i++){
		for(int j = 0; j < 10; j++){
            arr[i][j] = rand() % 9999 + 1;
            file << arr[i][j] << "|";
		}
    }
    file.close();
}
