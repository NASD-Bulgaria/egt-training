//============================================================================
// Name        : core1-string-1va-zadacha.cpp
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
	for(int i=0;i<str.length();i++)
	{
		if(isalpha(str.at(i)))
		{
		if(str.at(i)>='a'&&str.at(i)<='m')
		{
			str.at(i)+=13;
		}
		else
		{
			str.at(i)-=13;
		}
		}
	}
	cout<<str<<endl;
	return 0;
}
