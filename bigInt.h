#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

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

bigInt add(bigInt a, bigInt b);
bigInt sub(bigInt a, bigInt b);
bigInt mult(bigInt a, bigInt b);
bigInt div(bigInt a, bigInt b);
bigInt mod(bigInt a, bigInt b);
bigInt pow(bigInt a, int b);
bool equals(bigInt a, bigInt b);
bool gThan(bigInt a, bigInt b);
bool lThan(bigInt a, bigInt b);
// Adds the value of two bigInts
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
    bigInt sum = bigInt(total);
    return sum;
}
// Subtracts the value of two bigInts
bigInt sub(bigInt a, bigInt b){
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
	bigInt ans = bigInt(total);
	return ans;
}
// Multiplies the value of two bigInts
bigInt mult(bigInt a, bigInt b){
	bigInt total = (0);
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
		bigInt col = bigInt(colSum);
		total = add(total, col);
		zerCount++;
	}
	if (r > 0){
		total = bigInt(to_string(r) + total.toString());
	}
	return total;
}

bigInt div(bigInt a, bigInt b){

	bigInt sad = bigInt(0);
	return sad;
}

bigInt mod(bigInt a, bigInt b){

	bigInt sad = bigInt(0);
	return sad;
}
// Takes the value of bigInt "a" and raises it to the power of int "b"
bigInt pow(bigInt a, int b){
	bigInt ans = a;
	for (int i = 1; i < b; i++){
		ans = mult(ans, a);
	}
	return ans;
}
// Tests if two bigInts are of equal value
bool equals(bigInt a, bigInt b){
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
// Tests if the the bigInt "a" is greater than bigInt "b"
bool gThan(bigInt a, bigInt b){
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
// Tests if the bigInt "a" is less than bigInt "b"
bool lThan(bigInt a, bigInt b){
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
