#include <iostream>
#include "bigInt.h"

using namespace std;

int main(){
    bigInt num1 = bigInt(12);
    bigInt num2 = bigInt(1);
    cout << "Num1's value: " << num1.toString() << endl;
    cout << "Num2's value: " << num2.toString() << endl;
    cout << add(num1, num2).toString() << endl;
}