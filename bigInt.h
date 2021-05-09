/**
	BigInt: Creates and allows numerical 
		operations for the BigInt object
	@file BigInt.h
	@Author Ethan Rudy
	@Version 0.7 4/28/20
*/

#include <iostream>
#include <string>

using namespace std;
/*
	BigInt class and constructor declaration
*/
class BigInt{
	private:
		string num;

	public:
		// Default constructor
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
			for (int i = 0; i < n.length(); i++){
				if (int(n[i]) < 48 || int(n[i]) > 57){
					num = "0";
				}
			}
		}
		/*
			Sets the selected big into the the value of n
		*/
		void setVal(int n){
			num = to_string(n);
		}
		/*
			Sets the selected big into the the value of n
		*/
		void setVal(double n){
			num = to_string((int)n);
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
		}
		/*
			Returns the string value of selected BigInt
		*/
		string toString(){
			return num;
		}
		/*
			Returns the int value of the selected BigInt's length
		*/
		int length(){
			return num.length();
		}

		//YOU ARE MY FRIEND WOOOOOOOAAAAAAAAAAAAH
		friend ostream& operator<< (ostream&, const BigInt&);
};

ostream& operator<<(ostream& os, const BigInt& obj){
	os << obj.num;
	return os;
}