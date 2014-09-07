//============================================================================
// Name        : Structs.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	int bit = 16;
	cout<<(bitset<8>)bit<<endl;
	bit= bit>>4;
	cout<<(bitset<8>)bit<<endl;
	return 0;
}
