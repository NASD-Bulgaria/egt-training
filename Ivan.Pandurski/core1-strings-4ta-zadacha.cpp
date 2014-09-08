//============================================================================
// Name        : core1-strings-3ta-zadacha.cpp
// Author      : Ivan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
using namespace std;

int main() {
	string str;
	getline(cin,str);
	string::const_iterator iterator1=str.end();
	for(int i=0;i<str.length();i++)
	{
		if(isupper(str.at(i)))
		{
			str.at(i)=tolower(str.at(i));
		}
		else
		{
			str.at(i)=toupper(str.at(i));
		}
	}
	while(iterator1!=str.begin()-1)
	{
		cout<<*iterator1;
		iterator1--;

	}

	return 0;
}
