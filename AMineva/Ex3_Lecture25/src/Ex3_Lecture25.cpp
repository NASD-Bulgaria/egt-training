//============================================================================
// Name        : Ex3_Lecture25.cpp
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
	unsigned number;
	unsigned pow;
	cout << "Enter an integer : ";
	cin >> number;

	cout << "Enter an power : ";
	cin >> pow;

	cout<<"Number in bits is  : "<<bitset<4>(number)<<endl;

	number = number<<=pow;
	cout<<"Number after left shift is  : "<<number<<endl;
	cout<<"Number in bits is  : "<<bitset<4>(number)<<endl;

	return 0;
}
