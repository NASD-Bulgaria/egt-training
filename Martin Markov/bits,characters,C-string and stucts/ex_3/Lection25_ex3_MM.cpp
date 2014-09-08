//============================================================================
// Name        : Lection25_ex3_MM.cpp
// Author      : Martin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bitset>
using namespace std;


int main()
{   //Ќарочно е 16бита по добре показва преместването
	unsigned number;
	unsigned pow;
	cout << "Enter an integer : ";
	cin >> number;
	cout<<"Number in bits is  : "<<bitset<16>(number)<<endl;


	cout << "Enter an power : ";
	cin >> pow;
	number=number<<pow;

	cout<<"Integer after left shift is  : "<<number<<endl;
	cout<<"Number in bits is  : "<<bitset<16>(number)<<endl;


	return 0;
}
