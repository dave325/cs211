#include <iostream>
#include <cmath>
int main(){
	// Best way to compare floating point numbers is through checking the difference
	// The bad example
	if (1.0+2.0+3.0 == 1.0+2.0+3.0){
		std::cout <<"Equal" << std::endl;
	}else{
		std::cout << "Not equal" << std::endl;
	
	// Use for loop when you want to initialize start point and test ariable and increase based on result
	// Use while loop when you don't know the the specific length 
	// cmath library
		// Include cmath header file 
		// need to know the declarations to use 
	// to define function you need to specify the name, data type, and paramaters
		// function definition will have curly braces
		// function can return values 
		// scope rules -> global scope - variable is accessible everywhere | var scope -> accessible in file | local scope -> accessible to function
			// Never have global variables except 2 
				// cout and cin 
		 // pass parameters by value or reference
			// value will ube used but not the original variable 
			// reference -> pass actual variable to function and update will occur in original variable 
			// NEVER PASS A OBJECT BY VALUE - WASTE OF SPACE AND TIME CONSUMING
			// const reference -> cannot change it from function 
				//if you only want to use value in object and not change the actual value 
	// array -> aggregate data type 
	/* 
		void using magic numbers 
		create constants instead of actual number for size of array
		must iterate through array 
		array is a pointer -> and to access array from function you must pass a pointer to it 
					
	*/
	int testFunc(param1){ return 1;}
	
	return 0;
}
