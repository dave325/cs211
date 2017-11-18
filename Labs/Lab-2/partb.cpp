#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;
int main(){
	fstream outfile;
	int inarr[10][20];

	outfile.open("lab2.txt", fstream::in);

	if (!outfile.is_open())
	{
		cerr << "File did not open successfully when reading!!!" << endl;
		exit(1);
	}

	for (int c = 0; c < 20; c++){
		for (int r = 0; r < 10; r++)
		{
			outfile >> inarr[r][c];
			char ignore;
			outfile >> ignore;
		}
	}

	for (int r = 0; r < 10; r++){
		for (int c = 0; c < 20; c++){
			cout << inarr[r][c] << " ";
		}
		cout << endl;
	}
 
}
