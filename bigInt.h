/**
	BigInt: Creates and allows numerical 
		operations for the BigInt opject
	@file BigInt.h
	@Author Ethan Rudy
	@Version 0.7 4/28/20
*/
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

/**
	BigInt class and constructor declaration
*/
class BigInt{
    public:
        string num;
		// Defualt constructor
        BigInt(){
            num = "0";
        }
		// Integer constructor
        BigInt(int n){
            num = to_string(n);
        }
		// Double constructor
        BigInt(double n){
            num = to_string((int)n);
        }
		// String constructor
        BigInt(string n){
            num = n;
        }
        /*
			Returns a string value of a BigInt object
			@return string value of selected BigInt
		*/
        string toString(){
            return num;
        }
        /*
	`		Modifies the value of the selected BigInt
			@param string value being inserted
		*/
        void setVal(string n){
            num = n;
        }
		/*
	`		Modifies the value of the selected BigInt
			@param int value being inserted
		*/
        void setVal(int n){
            num = n;
        }
		/*
	`		Modifies the value of the selected BigInt
			@param double value being inserted
		*/
        void setVal(double n){
            num = (int)n;
        }
};
/*
	Adds the values of two BigInt objects
	@param:
		- a: First BigInt
		- b: Second BigInt
	@return: The sum of "a" and "b"
*/
BigInt add(BigInt a, BigInt b);
/*
	Subtracts the values of two BigInt objects
	@param:
		- a: First BigInt
		- b: Second BigInt
	@return: The difference of "a" and "b"
*/
BigInt sub(BigInt a, BigInt b);
/*
	Multiplies the values of two BigInt objects
	@param:
		- a: First BigInt
		- b: Second BigInt
	@return: The product of "a" and "b"
*/
BigInt mult(BigInt a, BigInt b);
/*
	Divides the values of two BigInt objects
	@param:
		- a: dividend
		- b: divisor
	@return: The quotient of "a" and "b"
*/
BigInt div(BigInt a, BigInt b);
/*
	Modulos the values of two BigInt objects
	@param:
		- a: First BigInt
		- b: Second BigInt
	@return: "a" modulos "b"
*/
BigInt mod(BigInt a, BigInt b);
/*
	Calculates the value of a BigInteger to the power of an int 
	@param:
		- a: First BigInt
		- b: Integer power that "a" is being raised too
	@return: "a" to the power of "b"
*/
BigInt pow(BigInt a, int b);
/*
	Calculates the value of BigInt!
	@param:
		- a: First BigInt
	@return: The sum of "a" and "b"
*/
BigInt factorial(BigInt a);
/*
	Calculates the square root of a
	@param:
		- a: First BigInt
	@return: The square root of "a"
*/
BigInt sqrt(BigInt a);
/*
	Compares the values of two BigInts
	@param Two BigInts to be compared
	@return
		- 1: a > b
		- 2: b > a
		- 0: a = b
*/
int compare(BigInt a, BigInt b);
/*
	Tests if the value of two BigInts are equal
	@param:
		- a: First BigInt
		- b: Second BigInt
	@return: If the two values are equal
*/
bool equals(BigInt a, BigInt b);
/*
	Tests if the value of the first BigInt is greater than the second's
	@param:
		- a: First BigInt
		- b: Second BigInt
	@return: If "a"'s value is greater than "b"'s
*/
bool gThan(BigInt a, BigInt b);
/*
	Tests if the value of the first BigInt is less than the second's
	@param:
		- a: First BigInt
		- b: Second BigInt
	@return: If "a"'s vlaue is less than "b"'s
*/
bool lThan(BigInt a, BigInt b);

// Adds the values of two BigInt objects
BigInt add(BigInt a, BigInt b){
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
    int r = 0;
    int pos2 = l2 - 1;
    for (int i = l1 - 1; i >= 0; i--){
        string d1 = num1.substr(i, 1);
        string d2;
        if (pos2 >= 0){
            d2 =  to_string(stoi(num2.substr(pos2, 1)) + r);
        } else {
            d2 = to_string(stoi("0") + r);
        }
        int digiSum = stoi(d1) + stoi(d2);
        if (to_string(digiSum).length() > 1){
            string t = to_string(digiSum);
            r = stoi(t.substr(0, t.length() - 1));
            string subDigi = t.substr(t.length() - 1, 1);
            total = subDigi + total;
        } else {
            total = to_string(digiSum) + total;
            r = 0;
        }
        pos2--;
    }
	if (r > 0){
		total = to_string(r) + total;
	}
	BigInt sum = BigInt(total);
    return sum;
}

// Subtracts the values of two BigInt objects
BigInt sub(BigInt a, BigInt b){
	if (equals(a, b)){
		return 0;
	}
	BigInt temp = BigInt(0);
	string n1, n2;
	bool flag = false;
	if (lThan(a, b)){
		n2 = a.toString();
		n1 = b.toString();
		flag = true;
	} else {
		n1 = a.toString();
		n2 = b.toString();
	}
	int pos1 = n1.length() - 1;
	int pos2 = n2.length() - 1;
	string total = "";
	while (pos1 >= 0){
		int d1 = stoi(n1.substr(pos1, 1));
		int d2;
		if (pos2 < 0){
			d2 = 0;
		} else {
			d2 = stoi(n2.substr(pos2, 1));
		}
		if (d1 >= d2){
			total = to_string(d1 - d2) + total;
		} else {
			if (stoi(n1.substr(pos1 - 1, 1)) == 0){
				int arr[n1.length()];
				for (int t = 0; t < pos1; t++){
					arr[t] = stoi(n1.substr(t, 1));
					//cout << arr[t] << endl;
				}
				bool zFlag = false;
				int nonZPos;
				//cout << sizeof(arr)/sizeof(arr[0]) << endl;
				for (int z = sizeof(arr)/sizeof(arr[0]) - 1; z >= 0; z--){
					//cout << z << ": " << arr[z] << endl;
					if (arr[z] == 0){
						arr[z] = 9;
						zFlag = true;
					} else {
						nonZPos = z;
					}
					//cout << z << endl;
					//cout << arr[z] << endl;
				}
				//cout << zFlag << endl;
				if (zFlag == true){
					arr[nonZPos] = arr[nonZPos] - 1;
				}
				for (int l = 0; l < sizeof(arr)/sizeof(arr[0]); l++){
					//cout << l << ": "<< arr[l] << endl;
				}
				string p1 = "";
				for (int l = 0; l < sizeof(arr)/sizeof(arr[0]); l++){
					p1 += to_string(arr[l]);
				}
				n1 = p1 + "9" + n1.substr(pos1, n1.length() - pos1); 
			} else {
				//Just carrying once
				n1 = n1.substr(0, pos1 - 1) 
				 + to_string(stoi(n1.substr(pos1 - 1, 1)) - 1) 
				 + n1.substr(pos1, n1.length() - pos1);
			}
			d1 += 10;
			total = to_string(d1 - d2) + total;
		}
		pos1--;
		pos2--;
	}
	int i = 0;
	while (true){
		if (total.substr(i, 1) == "0"){
			total = total.substr(i + 1, total.length() - i);
		} else {
			break;
		}
	}
	if (flag == true){
		total = "-" + total;
	}
	BigInt ans = BigInt(total);
	return ans;
}

// Multiplies the values of two BigInt objects
BigInt mult(BigInt a, BigInt b){
	BigInt total = (0);
	string num1 = a.toString();
	string num2 = b.toString();
	int l1 = num1.length();
	int l2 = num2.length();
	if (l1 < l2){
		string temp = num1;
		num1 = num2;
		num2 = temp;
		int lenTemp = 1;
		l1 = l2;
		l2 = lenTemp;
	}
	int r = 0;
	int zerCount = 0;
	for (int i = num2.length() - 1; i >= 0; i--){
		string colSum = "";
		for (int z = 0; z < zerCount; z++){
			colSum = "0" + colSum;
		}
		for (int ii = num1.length() - 1; ii >= 0; ii--){
			string d1 = num2.substr(i, 1);
			string d2 = num1.substr(ii, 1);
			int digiSum = (stoi(d1) * stoi(d2)) + r;
			if (to_string(digiSum).length() > 1){
				string t = to_string(digiSum);
				r = stoi(t.substr(0, t.length() - 1));
				string subDigi = t.substr(t.length() - 1, 1);
				colSum = subDigi + colSum;
			} else {
				colSum = to_string(digiSum) + colSum;
				r = 0;
			}
		}
		BigInt col = BigInt(colSum);
		total = add(total, col);
		zerCount++;
	}
	if (r > 0){
		total = BigInt(to_string(r) + total.toString());
	}
	return total;
}

// Divides the values of two BigInt objects
BigInt div(BigInt a, BigInt b){
	BigInt sad = BigInt(0);
	return sad;
}

// Calculates the value of a BigInteger to the power of an int 
BigInt mod(BigInt a, BigInt b){

	BigInt sad = BigInt(0);
	return sad;
}

// Calculates the value of a BigInteger to the power of an int 
BigInt pow(BigInt a, int b){
	BigInt ans = a;
	for (int i = 1; i < b; i++){
		ans = mult(ans, a);
	}
	return ans;
}

// Calculates the value of BigInt!
BigInt factorial(BigInt a){
	if (a.toString() == "0"){
		return BigInt(0);
	}
	BigInt i = a;
	BigInt s = BigInt(1);
	while (gThan(i, BigInt(0))){
		s = mult(s, i);
		i = sub(i, 1);
	}
	return s;
}

// Calculates the square root of a
BigInt sqrt(BigInt a){
	BigInt sad = BigInt(0);
	return sad;
}

int compare(BigInt a, BigInt b){
	if (a.toString().length() > b.toString().length()){
		return 1;
	}
	if (b.toString().length() > a.toString().length()){
		return 2;
	}
	int r = 0;
	for (int i = 0; i < a.toString().length(); i++){
		if (a.toString().substr(i, 1) > b.toString().substr(i, 1)){
			r = 1;
			break;
		}
		if (b.toString().substr(i, 1) > a.toString().substr(i, 1)){
			r = 2;
			break;
		}
	}
	return r;
}

// Tests if the value of two BigInts are equal
bool equals(BigInt a, BigInt b){
	if (compare(a, b) == 0){
		return true;
	}
	return false;
}

// Tests if the value of the first BigInt is greater than the second's
bool gThan(BigInt a, BigInt b){
	if (compare(a, b) == 1){
		return true;
	}
	return false;
}

// Tests if the value of the first BigInt is less than the second's
bool lThan(BigInt a, BigInt b){
	if (compare(a, b) == 2){
		return true;
	}
	return false;
}
