//============================================================================
// Name        : Ex5_Lecture25.cpp
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

void unpackCharacters(int charecters)
{
	int number = charecters>>8;
	int mask = 1;
	int newCharachter;

	for(int i = 0; i < 9; i ++)
	{
		newCharachter = mask | charecters;
		mask = mask << 1;
	}

	cout <<(bitset<16>) charecters << endl;
	cout <<(bitset<8>) newCharachter << endl;
	cout <<(bitset<8>) number << endl;

	cout << dec << (char)number << endl;
	cout << dec << (char)newCharachter << endl;

}

int main() {
	unpackCharacters(1111);
	return 0;
}
