//============================================================================
// Name        : RightShifts.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bitset>
using namespace std;

int power2(unsigned int, unsigned int);
unsigned int packCharacters(char, char);
void unpackCharacters(unsigned int);

int main() {
	//Ex.2
	int bit = 16;
	cout << (bitset<16>)bit << endl;
	bit = bit>>4;
	cout << (bitset<16>)bit << endl;
	cout << endl << endl;

	//Ex.3
	unsigned int number = 8;
	unsigned int pow = 2;

	cout << "number: " << number << endl <<(bitset<16>)number << endl;
	cout << "result: " << power2(number, pow) << endl << (bitset<16>)power2(number, pow);

	//Ex.4
	char a = 'a';
	char b = 'b';
	packCharacters(a, b);

	//Ex.5
	unpackCharacters(packCharacters(a, b));

	return 0;
}

int power2(unsigned int number, unsigned int pow){
	return number = number << pow;
}

unsigned int packCharacters(char char1, char char2){
	unsigned int number1;
	unsigned int number2;
	cout << endl << endl << endl;
	cout << (bitset<8>)char1 << endl;
	cout << (bitset<8>)char2 << endl;
	number1 = char1 << 8;
	number2 = number1 | char2;
	cout << (bitset<16>)number2 << endl;
	return number2;
}

void unpackCharacters(unsigned int number){
	char char1;
	char char2;
	unsigned int mask1 = 65280;
	unsigned int mask2 = 255;
	unsigned int temp;

	temp = number & mask1;
	temp = temp >> 8;
	char1 = temp;

	temp = number & mask2;
	char2 = temp;

	cout << "char 1: " << char1 << endl;
	cout << "char 2: " << char2 << endl;
}
