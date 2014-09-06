//============================================================================
// Name        : RightShiftBits.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
#include <bitset>
using namespace std;

int main() {
	int a;
	cout << "Enter a: ";
	cin>>a;
	cout << (bitset<8>) a;
	a = a>>4;
	cout<< endl;
	cout << (bitset<8>) a<<endl;
	cout << a;
	return 0;
}
