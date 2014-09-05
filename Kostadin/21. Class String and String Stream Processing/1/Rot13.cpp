//============================================================================
// Name        : Rot13.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	cout << "Enter string: ";
	getline(cin, a);
	char tmp;
	string res = "";
	for(int i = 0; i < a.length(); i++)
	{
		tmp = a.at(i);
		tmp = tmp + 13;
		res += tmp;
	}
	cout<< res<< endl;


	string decRes = "";
	for(int i = 0; i < res.length(); i++)
	{
		tmp = res.at(i);
		tmp -= 13;
		decRes += tmp;
	}
	cout << decRes;
	return 0;
}
