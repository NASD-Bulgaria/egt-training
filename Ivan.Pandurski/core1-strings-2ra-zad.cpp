//============================================================================
// Name        : core1-strings-1va-zad.cpp
// Author      : Ivan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	vector<string> newstr;
	string str1;
	string str2;
	string str3;
	getline(cin,str1);
	getline(cin,str2);
	getline(cin,str3);
	newstr.push_back(str1);
	newstr.push_back(str2);
	newstr.push_back(str3);
	for(int i=0;i<3;i++)
	{
		if(newstr[i].rfind("r")==newstr[i].length()-1)
			{cout<<newstr[i]<<endl;}
		if(newstr[i].rfind("ay")==newstr[i].length()-2)
		{
			cout<<newstr[i]<<endl;
		}
	}
	return 0;
}
