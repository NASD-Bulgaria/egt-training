//============================================================================
// Name        : Pyramide.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

string revString(string a)
{
	string b = "";
	for(int i = a.length() - 1; i >=0; i--)
	{
		b += a.at(i);
	}
	return b;
}

int main() {
	string str = "abcdefghijklmnopqrstuvwxyz{";
	int index = 0;
	int count = 1;
	for(int j = 0; j < 14; j++)
	{
		for(int i = 0; i < 27; i++)
		{
			cout<<" ";
			if(i == 27/2 - index)
			{
				cout << str.substr(index, count);
				cout << revString(str.substr(count - 1, index));
			}
		}
		count++;
		index++;
		cout<<endl;
	}


	return 0;
}
