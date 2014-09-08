//============================================================================
// Name        : ex_bitset5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bitset>

using namespace std;

unsigned int packCharacters(char letter1, char letter2);
void unpackCharacters(unsigned int);

int main()
{
	char a = 'a';
	char b = 'b';

	int c;
	c = packCharacters(a,b);
	cout<<c<<endl;

	unpackCharacters(packCharacters(a,b));

	return 0;
}


unsigned int packCharacters(char letter1, char letter2)
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

	return b;
}

void unpackCharacters(unsigned int number)
{
	char letter1;
	char letter2;
	unsigned int mask1 = 65280;
	unsigned int mask2 = 255;
	unsigned int temp;

	temp = number & mask1;
	temp = temp >> 8;

	letter1 = temp;

	temp = number & mask2;
	letter2 = temp;

	cout << "Letter1: "<< letter1<<endl;
	cout << "Letter2: "<< letter2<<endl;

}


