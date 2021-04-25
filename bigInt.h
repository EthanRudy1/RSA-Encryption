#include <iostream>
#include <string>

using namespace std;

class bigInt{
    public:
        string num;
        /*
        Constructors: (in order)
        - Default constructor
        - Integer constructor
        - Double constructor
        - String constructor
        */
        bigInt(){
            num = "0";
        }
        bigInt(int n){
            num = to_string(n);
        }
        bigInt(double n){
            num = to_string((int)n);
        }
        bigInt(string n){
            num = n;
        }
        /*
        To string
        */
        string toString(){
            return num;
        }
        /*
        Mutator methods: (in order)
        - Passing value as a stirng
        - Passing value as an integer
        - Passing a value as a double
        */
        void setVal(string n){
            num = n;
        }
        void setVal(int n){
            num = n;
        }
        void setVal(double n){
            num = (int)n;
        }
};

 /*
Adding:
- How it works: 
    - So basically, i loop through the longest number (right to left),
      adding up the digits and then grabbing the remainder
    - This repeats every iteration until the end
- Things to keep in mind:
    - When the larger number is greater than the shorter number,
      we have to make the other digit value equal to zero in order to not cause an overflow exception
*/
bigInt add(bigInt a, bigInt b){
    string total = "";
    string num1 = a.toString();
    string num2 = b.toString();
    int l1 = num1.length();
    int l2 = num2.length();
    if (l1 < l2){
        string temp = num1;
        num1 = num2;
        num2 = temp;
        int lenTemp = l1;
        l1 = l2;
        l2 = lenTemp;
    }
    cout << num1 << ": " << l1 << endl;
    cout << num2 << ": " << l2 << endl;
    bigInt t = bigInt(0);
    return t;
}