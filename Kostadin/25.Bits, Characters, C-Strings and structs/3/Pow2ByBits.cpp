//============================================================================
// Name        : Pow2ByBits.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bitset>
using namespace std;

int main() {
	unsigned int a;
	cout << "Enter a: ";
	cin >> a;
	unsigned int pow;
	cout << "Enter pow: ";
	cin >> pow;
	cout<< a << endl;
	cout << "a in bits is "<< (bitset<8>)a << endl;
	a = a<<pow;
	cout << "a in bits after pow: "<< (bitset<8>)a << endl;
	cout << a << endl;
	return 0;
}
