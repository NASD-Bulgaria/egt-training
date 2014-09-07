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

void bitWise(int);
int power(int ,int);
int main() {
	int bit = 2;
	int powerer = 2;
	int result;
	result =power(bit,powerer);
	cout<< result<<endl;
	bitWise(result);
	return 0;
}
void bitWise(int bit)
{
	cout<<(bitset<8>)bit<<endl;
}

int power(int number, int power2)
{
	return number<<power2;
}
