#include <iostream>
#include "bigInt.h"

using namespace std;

int main(){
    bigInt num1 = bigInt("112233445566778899");
    bigInt num2 = bigInt(18);
    cout << add(num1, num2).toString() << endl;
}