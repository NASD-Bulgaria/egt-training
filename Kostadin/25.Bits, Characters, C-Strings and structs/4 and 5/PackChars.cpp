//============================================================================
// Name        : PackChars.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include<bitset>
using namespace std;
void unpackChars(int b)
{
	int a = b>>8;
	int mask = 1;
	int newB;

	for(int i = 0; i < 8; i ++)
	{
		newB = mask | b;
		mask = mask << 1;
	}

	cout <<(bitset<16>) b << endl;
	cout <<(bitset<8>) newB << endl;
	cout <<(bitset<8>) a << endl;

	cout << dec << (char)a << endl;
	cout << dec << (char)newB << endl;

}
int packChars(char a, char b)
{
	int bitA;
	int bitB;
	bitA = a<<8;
	bitB = bitA|b;

	cout << (bitset<8>) a<< endl;
	cout << (bitset<8>) b<< endl;

	cout << (bitset<16>) bitB<< endl;

	return bitB;
}
int main() {
//	char a = 'a';
//	char b = 'b';
//
//	cout<< packChars(a, b);


	unpackChars(2155);
	return 0;
}
