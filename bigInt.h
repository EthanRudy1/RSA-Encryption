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
#include <algorithm>

using namespace std;

/**
	BigIn class and constructor declaration
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
		- a: First BigInt
		- b: Second BigInt
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
	string num1 = a.toString();
	string num2 = b.toString();
	bool flag = false;
	if (lThan(a, b)){
		flag = true;
		num1 = b.toString();
		num2 = a.toString();
	}
	string total = "";
	int pos = num2.length() - 1;
	for (int i = num1.length() - 1; i >= 0; i--){
		int digi1 = stoi(num1.substr(i, 1));
		int digi2;
		if (pos >= 0){
			digi2 = stoi(num2.substr(pos, 1));
		} else {
			digi2 = 0;
		}
		pos--;
		int diff;
		if (digi1 > digi2){
			diff = digi1 - digi2;
		} else if (digi1 == digi2){
			diff = 0;
		} else {
			num1 = num1.substr(0, i - 1) + to_string(stoi(num1.substr(i - 1, 1)) - 1) + num1.substr(i, num1.length() - i);
			digi1 += 10;
			diff = digi1 - digi2;
		}
		total = to_string(diff) + total; 
	}
	int p = 0;
	while (true){
		if (total.substr(p, 1) == "0"){
			total.erase(p, 1);
			p--;
		} else {
			break;
		}
		p++;
	}
	if (flag){
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
	BigInt i = a;
	BigInt s = BigInt(1);
	while (gThan(i, BigInt(2))){
		s = mult(s, i);
		i = sub(i, BigInt(1));
	}
	//BigInt sad = BigInt(0);
	return s;
}

// Calculates the square root of a
BigInt sqrt(BigInt a){
	BigInt sad = BigInt(0);
	return sad;
}

// Tests if the value of two BigInts are equal
bool equals(BigInt a, BigInt b){
	if (a.toString().length() != b.toString().length()){
		return false;
	}
	for (int i = 0; i < a.toString().length(); i++){
		int d1 = stoi(a.toString().substr(i,1));
		int d2 = stoi(b.toString().substr(i,1));
		if (d1 != d2){
			return false;
		}
	}
	return true;
}

// Tests if the value of the first BigInt is greater than the second's
bool gThan(BigInt a, BigInt b){
	if (a.toString().length() > b.toString().length()){
		return true;
	} else if (a.toString().length() < b.toString().length()){
		return false;
	}
	for (int i = 0; i < a.toString().length(); i++){
		int d1 = stoi(a.toString().substr(i, 1));
		int d2 = stoi(b.toString().substr(i, 1));
		if (d1 < d2){
			return false;
		}
	}
	if (!equals(a, b)){
		return true;
	}
	return true;
}

// Tests if the value of the first BigInt is less than the second's
bool lThan(BigInt a, BigInt b){
	if (a.toString().length() < b.toString().length()){
		return true;
	} else if (a.toString().length() > b.toString().length()){
		return false;
	}
	for (int i = 0; i < b.toString().length(); i++){
		int d1 = stoi(a.toString().substr(i, 1));
		int d2 = stoi(b.toString().substr(i, 1));
		if (d1 > d2){
			return false;
		}
	}
	if (!equals(a, b)){
		return true;
	}
	return true;
}
