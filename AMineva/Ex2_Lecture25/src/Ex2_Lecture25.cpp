//============================================================================
// Name        : Ex2_Lecture25.cpp
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
	unsigned value;
	cout << "Enter an unsigned integer : ";
	cin >> value;
	cout<<bitset<4>(value)<<endl;
	value>>=1;
	cout<<bitset<4>(value)<<endl;
	cout<<value;

	return 0;
}
