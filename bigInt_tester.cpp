#include <iostream>
#include "bigInt.h"

using namespace std;

int main() {
	bigInt num1 = bigInt("10");
	bigInt num2 = bigInt("12");
	cout << "Showcase: " << num1.toString() << " and " << num2.toString() << endl;
	cout << "Adding: " << endl;
	cout << add(num1, num2).toString() << endl;
	cout << "Subtracting: " << endl;
	cout << sub(num1, num2).toString() << endl;
	cout << "Multiplying: " << endl;
	cout << mult(num1, num2).toString() << endl; 
	cout << "Power: (num1) squared" << endl;
	cout << pow(num1, 2).toString() << endl;
}
