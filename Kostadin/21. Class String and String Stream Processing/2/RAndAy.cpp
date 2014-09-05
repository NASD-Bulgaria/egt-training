//============================================================================
// Name        : RAndAy.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string str1 = "car";
	string str2 = "fly";
	string str3 = "lay";
	string str4 = "pay";
	vector <string> strings;
	strings.push_back(str1);
	strings.push_back(str2);
	strings.push_back(str3);
	strings.push_back(str4);
	for(int i = 0; i < strings.size(); i++)
	{
		if((strings[i].at(strings[i].length() - 1) == 'r')
			||((strings[i].at(strings[i].length() - 1) == 'y')&&(strings[i].at(strings[i].length() - 2) == 'a')))
		{
			cout << strings[i]<< endl;
		}
	}
	return 0;
}
