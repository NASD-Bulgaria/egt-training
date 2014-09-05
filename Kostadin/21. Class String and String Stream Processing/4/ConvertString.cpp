//============================================================================
// Name        : ConvertString.cpp
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
	cout << "Enter a string: ";
	getline(cin, a);
	string rev = "";
	for(int i = a.length() - 1; i >= 0; i--)
	{
		if(islower(a.at(i)))
		{
			a.at(i) = toupper(a.at(i));
		}
		else
		{
			a.at(i) = tolower(a.at(i));
		}
		rev += a.at(i);
	}
	cout << rev<< endl;
	return 0;
}
