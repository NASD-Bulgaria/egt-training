//============================================================================
// Name        : Lection25_Ex2_MM.cpp
// Author      : Martin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	unsigned value;
	cout << "Please insert an unsigned integer : ";
	cin >> value;
	cout<<"Your Integer is: "<<value<<" ";
	cout<<"In Bits is: "<<bitset<4>(value)<<endl;
	value>>=1;
	cout<<"After right-shifts ,your value in bits is: "<<bitset<4>(value)<<endl;
	cout<<"Your now integer value is: "<<value;

	return 0;
}
