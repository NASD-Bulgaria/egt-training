//============================================================================
// Name        : stringStream.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
//#include <sstream>
using namespace std;

void encrypt(string &);

int main() {

	cout << "Enter string: ";
	string s;
	getline (cin,s);
	encrypt(s);

	return 0;
}

void encrypt(string &a)
{
	char c;
		string result="";
		for (int i = 0; i < a.length(); i++)
		{
			c = a[i];
			if ((c >= 65 && c <= 90 )|| (c >= 97 && c <= 122) ){
			if (c <= 109 && c >= 97)
			{
				result = result.append(1,c+13);
			}
			if (c > 109 && c <= 122)
			{
				result = result.append(1,c-13);
			}
			if (c <= 77 && c >= 65)
			{
				result=result.append(1,c+13);
			}
			if (c > 77 && c <= 90)
			{
				result = result.append(1,c-13);
			}
			}
			else
			{
				result = result.append(1,c);
			}
	     }
		cout << result;

}
