/**
	BigInt: Simple tester for the BigInt.h header file
	@file main.cpp
	@Author Ethan Rudy
	@Version 0.7 4/28/20
*/
#include <iostream>
#include "BigInt.h"

using namespace std;

int main() {
	BigInt num1 = BigInt("10");
	BigInt num2 = BigInt("12");
	cout << "Showcase: " << num1.toString() << " and " << num2.toString() << endl;
	cout << "Adding: " << endl;
	cout << add(num1, num2).toString() << endl;
	cout << "Subtracting: " << endl;
	cout << sub(num1, num2).toString() << endl;
	cout << "Multiplying: " << endl;
	cout << mult(num1, num2).toString() << endl; 
	cout << "Power: (num1) squared" << endl;
	cout << pow(num1, 2).toString() << endl;
	cout << "Factorial: (num1)" << endl;
	cout << factorial(num1).toString() << endl;
}
