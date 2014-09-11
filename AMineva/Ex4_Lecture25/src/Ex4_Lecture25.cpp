//============================================================================
// Name        : Ex4_Lecture25.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bitset>
using namespace std;

void packCharacters(char char_1, char char_2){
	unsigned numberFirst;
	unsigned numberSecond;
	cout << (bitset<8>)char_1 << endl;
	cout << (bitset<8>)char_2 << endl;
	numberFirst = char_1 << 8;
	numberSecond = numberFirst | char_2;
	cout << (bitset<16>)numberSecond << endl;
}

int main()
{
	char first = 'a';
	char second = 'b';
	packCharacters(first, second);

	return 0;
}
