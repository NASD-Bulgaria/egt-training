//============================================================================
// Name        : ex_bitset1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

int power2(int number, int pow);

int main()
{
//	int bit = 10;
//	cout<<(bitset<16>)bit<<endl;
//
//	bit = bit>>3;
//	cout<<(bitset<16>)bit<<endl;


	unsigned number = 2;
	unsigned pow = 2;
//	cout<<(bitset<16>)number<<endl;

//	number = number << 1;
//	cout<<(bitset<16>)number<<endl;

	cout<<" Number: "<< number<<endl<<(bitset<16>)number<<endl;
	cout<<" Result: "<< power2(number, pow)<<endl;
	cout<<(bitset<16>)power2(number, pow);

	return 0;
}


int power2(int number, int pow)
{
	return number = number << (pow);
}
