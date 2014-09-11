//============================================================================
// Name        : Ex7_String_Legture.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverse(string str)
{
	string temp;
	for(int i=str.length()-1; i>=0; i--) temp+=str[i];
	return temp;
}

int main()
{
	string str = "abcdefghijklmnopqrstuvwxyz{";
	string space = "             ";
	int start = 0;
	int len = 1;

	for(int i=1; i<=14; i++)
	{
		string temp.append(space);
		temp.append(str.substr(start, len));
		temp.append(reverse(str.substr(start, len-1)));
		temp.append(space);
		space = space.substr(0, space.length()-1);
		start ++;
		len ++;
		cout<<temp<<endl;
	}

	return 0;
}
