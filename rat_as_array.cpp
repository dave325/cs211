#include <iostream>
void input(int r[]);
void output(int r[]);
void add(int r[], int r2[], int r3[]);
int lcm(int a, int b);
int gcd(int a, int b);
int main(){
	int r1[2];
	int r2[2];
	int r3[2];
	input(r1);
	input(r2);
	add(r1, r2, r3);
	std::cout << "Sum of: ";
	output(r1);
	std::cout << " and ";
	output(r2);
	std::cout << " = "l
	output(r3);
	return 0;
}
void input(int r[]){
	std::cout << "num: ";
	std::cin >> r[0];
	std::cout << "denom: ";
	std::cin >> r[1];
}
void output(int r[]){
	std::cout << r[0] << "/" <<r[1];
}
int gcd(int a, int b){
	int c = a;
	while(b != 0){
		c =a;
		a = b;
		b = c % b;
	}
	return a;
}
int lcm(int a, int b){
	return (a * b) / gcd(a,b);
}
void add(int r1[], int r2[], int r3[]){
	int ell = lcm(r1[1],r2[1]);
	r3[1] = ell;
	r3[0] = r1[0] * ell/r1[1] + r2[0] * ell/r2[1];

}
