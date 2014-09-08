//============================================================================
// Name        : ex_bitset4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bitset>
using namespace std;

void packCharacters(char letter1, char letter2);

int main()
{
char a = 'a';
char b = 'b';

packCharacters(a,b);



	return 0;
}

void packCharacters(char letter1, char letter2)
{
	unsigned int a;
	unsigned int b;

	cout<<(bitset<8>)letter1;
	cout<<"   combined with   ";

	cout<<(bitset<8>)letter2;

	a = letter1 << 8;
	b = a | letter2;
	cout<<"   =   ";
	cout<<(bitset<16>)b<<endl;
}
