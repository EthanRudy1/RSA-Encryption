/**
	BigInt: Creates and allows numerical 
		operations for the BigInt object
	@file BigInt.h
	@Author Ethan Rudy
	@Version 0.7 4/28/20
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
/*
	BigInt class and constructor declaration
*/
class BigInt{
	private:
		string num;
		bool negative = false;
	public:
		// Default constructor
		BigInt(){
			num = "0";
		}
		// Integer constructor
		BigInt(int n){
			num = to_string(n);
			if (to_string(n)[0] == '-'){
				negative = true;
			}
		}
		// Double constructor
		BigInt(double n){
			num = to_string((int)n);
			if (to_string(n)[0] == '-'){
				negative = true;
			}
		}
		// String constructor
		BigInt(string n){
			num = n;
			for (int i = 0; i < n.length(); i++){
				if (int(n[i]) < 48 || int(n[i]) > 57){
					if (n[i] != '-'){
						num = "0";
					}
				}
			}
			if (n[0] == '-'){
				negative = true;
			}
		}
		/*
			Sets the selected big into the the value of n
		*/
		void setVal(int n){
			num = to_string(n);
			if (to_string(n)[0] == '-'){
				negative = true;
			}
		}
		/*
			Sets the selected big into the the value of n
		*/
		void setVal(double n){
			num = to_string((int)n);
			if (to_string(n)[0] == '-'){
				negative = true;
			}
		}
		/*
			Sets the selected big into the the value of n
		*/
		void setVal(string n){
			num = n;
			for (int i = 0; i < n.length(); i++){
				if (int(n[i]) < 48 || int(n[i]) > 57){
					num = "0";
				}
			}
			if (n[0] == '-'){
				negative = true;
			}
		}

		/*
			Returns the string value of selected BigInt
			@return: string value of selected BigInt
		*/
		string toString(){
			return num;
		}

		/*
			Returns the int value of the selected BigInt's length
			@return: length of the value of selected BigInt
		*/
		int length(){
			return num.length();
		}

		/*
			Returns a digit at a specified index
			@return: int value of a digit at specified index
		*/
		int digiAt(int i){
			return num[i] - 48;
		}

		//YOU ARE MY FRIEND WOOOOOOOAAAAAAAAAAAAH
		friend ostream& operator<< (ostream&, const BigInt&);

		///// EQUAL /////

		/*
			Detects if the value of two BigInts are equal
			@param:
				- BigInt a: Second value to be tested
			@return: If the values are equal
		*/
		bool operator==(const BigInt& a){
			string num1 = num;
			string num2 = a.num;
			if (num1.length() != num2.length()){
				return false;
			}
			for (int i = 0; i < num1.length(); i++){
				if (num1[i] != num2[i]){
					return false;
				}
			}
			return true;
		}

		/*
			Detects if the value of a BigInt and a int are equal
			@param:
				- int a: Second value to be tested
			@return: If the values are equal
		*/
		bool operator==(const int& a){
			return operator==(BigInt(a));
		}

		/*
			Detects if the value of a BigInt and a double are equal
			@param:
				- double a: Second value to be tested
			@return: If the values are equal
		*/
		bool operator==(const double& a){
			string num1 = num;
			string num2 = to_string(a); // Including decimals
			string tNum2 = to_string((int)a); // Without decimals
			if (num1.length() != tNum2.length()){
				return false;
			} else {
				int ind = num2.find('.', 0);
				if (stoi(num2.substr(ind + 1)) > 0){
					return false;
				}
			}
			for (int i = 0; i < num1.length(); i++){
				if (num1[i] != tNum2[i]){
					return false;
				}
			}
			return true;
		}

		/*
			Detects if the value of a BigInt and a string are equal
			@param: 
				- string a: Second value to be tested
			@return: If the values are equal
		*/
		bool operator==(const string& a){
			return operator==(BigInt(a));
		}
		
		///// LESS THAN /////

		/*
			Detects if a value of a BigInt is less than the selected
			@param:
				- BigInt a: Second value to be tested
			@return: if the selected is less than a
		*/
		bool operator<(const BigInt& a){
			string num1 = num;
			string num2 = a.num;
			if (num1 == num2){
				return false;
			}
			if (!negative && a.negative){
				return false;
			} else if (negative && !a.negative){
				return true;
			} else if (!negative && !a.negative){
				if (num1.length() < num2.length()){
					return true;
				} else if (num2.length() < num1.length()){
					return false;
				} else {
					for (int i = 0; i < num1.length(); i++){
						if (num1[i] > num2[i]){
							return false;
						}
					}
				}
			} else if (negative && a.negative){
				if (num1.length() > num2.length()){
					return true;
				} else if (num2.length() < num1.length()){
					return false;
				} else {
					for (int i = 1; i < num1.length(); i++){
						if (num1[i] < num2[i]){
							return false;
						}
					}
				}
			}
			return true;
		}

		/*
			Detects if a value of an int is less than the selected
			@param:
				- int a: Second value to be tested
			@return: if the selected is less than a
		*/
		bool operator<(const int& a){
			return operator<(BigInt(a));
		}

		/*
			Detects if a value of a double is less than the selected
			@param:
				- double doubA: Second value to be tested
			@return: if the selected is less than a
		*/
		bool operator<(const double& doubA){
			string num1 = num;
			string num2 = to_string(doubA);
			string tNum2 = to_string((int)doubA);
			BigInt a = BigInt(tNum2);
			if (negative && !a.negative){
				return true;
			} else if (!negative && a.negative){
				return false;
			} else if (!negative && !a.negative){
				if (num1.length() < tNum2.length()){
					return true;
				} else if (tNum2.length() < num1.length()){
					return false;
				} else {
					for (int i = 0; i < num1.length(); i++){
						if (num1[i] > tNum2[i]){
							return false;
						}
					}
					int ind = num2.find('.', 0);
					if (stoi(num2.substr(ind + 1)) > 0){
						return true;
					}
				}
			} else if (negative && a.negative){
				if (num1.length() < tNum2.length()){
					return false;
				} else if (tNum2.length() < num1.length()){
					return true;
				} else {
					for (int i = 1; i < num1.length(); i++){
						if (num1[i] < num2[i]){
							return false;
						}
					}
					int ind = num2.find('.', 0);
					if (stoi(num2.substr(ind + 1)) > 0){
						return false;
					}
				}
			}
			return true;
		}
		/*
			Detects if a value of a string is less than the selected
			@param:
				- string a: Second value to be tested
			@return: if the selected is less than a
		*/
		bool operator<(const string& a){
			return operator<(BigInt(a));
		}

		///// GREATER THAN /////

		/*
			Detects if a value of a BigInt is greater than the selected
			@param:
				-BigInt a: Second value to be tested
			@return: if the selected is greater than a
		*/
		bool operator>(const BigInt& a){
			return !operator==(a) && !operator<(a);
		}

		/*
			Detects if a value of an int is greater than the selected
			@param:
				-int a: Second value to be tested
			@return: if the selected is greater than a
		*/
		bool operator>(const int& a){
			return !operator==(a) && !operator<(a);
		}

		/*
			Detects if a value of a double is greater than the selected
			@param:
				-double a: Second value to be tested
			@return: if the selected is greater than a
		*/
		bool operator>(const double& a){
			return !operator==(a) && !operator<(a);
		}

		/*
			Detects if a value of a string is greater than the selected
			@param:
				-string a: Second value to be tested
			@return: if the selected is greater than a
		*/
		bool operator>(const string& a){
			return !operator==(a) && !operator<(a);
		}

		///// LESS THAN OR EQUAL /////

		/*
			Detects if a value of a BigInt is less than or equal to the selected
			@param:
				- BigInt a: Second value to be tested
			@return : if the selected value is less than or equal to a
		*/
		bool operator<=(const BigInt& a){
			return operator==(a) || operator<(a);
		}

		/*
			Detects if a value of an int is less than or equal to the selected
			@param:
				- int a: Second value to be tested
			@return : if the selected value is less than or equal to a
		*/
		bool operator<=(const int& a){
			return operator==(a) || operator<(a);
		}

		/*
			Detects if a value of a double is less than or equal to the selected
			@param:
				- double a: Second value to be tested
			@return : if the selected value is less than or equal to a
		*/
		bool operator<=(const double& a){
			return operator==(a) || operator<(a);
		}

		/*
			Detects if a value of a string is less than or equal to the selected
			@param:
				- string a: Second value to be tested
			@return : if the selected value is less than or equal to a
		*/
		bool operator<=(const string& a){
			return operator==(a) || operator<(a);
		}

		///// GREATER THAN OR EQUAL /////

		/*
			Detects if a value of a BigInt is greater than or equal to the selected
			@param:
				- BigInt a: Second value to be tested
			@return : if the selected value is greater than or equal to a
		*/
		bool operator>=(const BigInt& a){
			return operator==(a) || operator>(a);
		}

		/*
			Detects if a value of an int is greater than or equal to the selected
			@param:
				- int a: Second value to be tested
			@return : if the selected value is greater than or equal to a
		*/
		bool operator>=(const int& a){
			return operator==(a) || operator>(a);
		}

		/*
			Detects if a value of a double is greater than or equal to the selected
			@param:
				- double a: Second value to be tested
			@return : if the selected value is greater than or equal to a
		*/
		bool operator>=(const double& a){
			return operator==(a) || operator>(a);
		}

		/*
			Detects if a value of a string is greater than or equal to the selected
			@param:
				- string a: Second value to be tested
			@return : if the selected value is greater than or equal to a
		*/
		bool operator>=(const string& a){
			return operator==(a) || operator>(a);
		}


		///// Not EQUAL /////

		/*
			Detects if a value of a BigInt is not equal to the selected
			@param:
				- BigInt a: Seconds value to be tested
			@return: if the selected's value doesn't equal a's value
		*/
		bool operator!=(const BigInt& a){
			return !operator==(a);
		}
		/*
			Detects if a value of a int is not equal to the selected
			@param:
				- int a: Seconds value to be tested
			@return: if the selected's value doesn't equal a's value
		*/
		bool operator!=(const int& a){
			return !operator==(a);
		}

		/*
			Detects if a value of a double is not equal to the selected
			@param:
				- double a: Seconds value to be tested
			@return: if the selected's value doesn't equal a's value
		*/
		bool operator!=(const double& a){
			return !operator==(a);
		}

		/*
			Detects if a value of a string is not equal to the selected
			@param:
				- string a: Seconds value to be tested
			@return: if the selected's value doesn't equal a's value
		*/
		bool operator!=(const string& a){
			return !operator==(a);
		}

		///// ADDING /////

		/*
			Adds the value of two BigInts
			@param: 
				- BigInt a: Second value to be added
			@return: the sum of two BigInts
		*/
		BigInt operator+(const BigInt& a){
			
			return BigInt(0);
		}

		/*
			Adds the value of a BigInts and an Integer
			@param:
				- int a: second value to be added
			@return: the sum of the passed integer and the selected BigInt
		*/
		BigInt operator+(const int& a){
			return operator+(BigInt(a));
		}

		/*
			Adds the value of a BigInts and an double
			@param:
				- double a: second value to be added
			@return: the sum of the passed double and the selected BigInt	
		*/
		BigInt operator+(const double& a){
			return operator+(BigInt(a));
		}

		/*
			Adds the value of a BigInts and an string
			@param:
				- string a: second value to be added
			@return: the sum of the passed string and the selected BigInt
		*/
		BigInt operator+(const string& a){
			return operator+(BigInt(a));
		}

};

/*
	Returns the absolute value of a selected BigInt
	@param: 
		- BigInt a: value to be abs'd
	@return: the absolute value of a 
*/
BigInt abs(BigInt a){
	if (a.toString()[0] == '-'){
		return BigInt(a.toString().substr(1));
	}
	return BigInt(a.toString());
}

/*
	Returns the reverse of the selected BigInt
	@param:
		- BigInt a: value to be reversed
	@return: the reversed value of a
*/
BigInt rev(BigInt a){
	string num = a.toString();
	bool flag = false;
	if (num[0] == '-'){
		num = num.substr(1);
		flag = true;
	}
	reverse(num.begin(), num.end());
	if (flag == true){
		num = "-" + num;
	}
	return BigInt(num);
}

ostream& operator<<(ostream& os, const BigInt& obj){
	os << obj.num;
	return os;
}
