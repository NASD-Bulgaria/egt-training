//============================================================================
// Name        : Ex2_Lecture26_B.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string str = "This is the TEXT. Text, text, text – THIS TEXT! Is this the text?";
	stack<string>s;

	for(unsigned i=0; i<str.length(); i++)
	{
		if(!isalpha(str[i]))
		{
			string symbol(1,str[i]);
			s.push(symbol);
		}
		else
		{
			string word="";
			while(isalpha(str[i]))
			{
				word += str[i];
				i++;
			}
			s.push(word);
			i--;
		}
	}

	string reverseStr;
	while(!s.empty())
	{
		reverseStr.append(s.top());
		s.pop();
	}

	cout<<reverseStr;

	return 0;
}
