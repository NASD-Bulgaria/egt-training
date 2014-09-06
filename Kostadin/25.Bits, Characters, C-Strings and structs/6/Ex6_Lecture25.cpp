//============================================================================
// Name        : Ex6_Lecture25.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	string temp;

	do{
		cout<<"Enter symbol or \"end\" for exit : ";
		cin>>temp;

		if(temp.length()<3 && temp!="end")
		{
			char symbol = temp[0];

			if(isalpha(symbol))
			{
				cout<<symbol<<" - is alpha;"<<endl;

				if(islower(symbol)) {
					cout<<symbol<<" - is lower!"<<endl;
					cout<<(char)toupper(symbol)<<" - is upper!"<<endl;
				}

				if(isupper(symbol))
				{
					cout<<symbol<<" - is upper!"<<endl;
					cout<<(char)tolower(symbol)<<" - is tolower!"<<endl;
				}
			}
			else cout<<symbol<<" - is not alpha;"<<endl;

			if(isdigit(symbol)) cout<<symbol<<" - is digit;"<<endl;
			else cout<<symbol<<" - is not digit;"<<endl;

			if(isalnum(symbol)) cout<<symbol<<" - is or alpha or digit;"<<endl;
			else cout<<symbol<<" - is or not alpha or not digit;"<<endl;

			if(ispunct(symbol)) cout<<symbol<<" - is punctuation!"<<endl;

			else cout<<symbol<<" - is not punctuation!"<<endl;

			if(iscntrl(symbol)) cout<<symbol<<" - is cntrl!"<<endl;
			else cout<<symbol<<" - is not cntrl!"<<endl;

			if(isspace(symbol)) cout<<symbol<<" - is space!"<<endl;
			else cout<<symbol<<" - is not space!"<<endl;

			if(isprint(symbol)) cout<<symbol<<" - is print!"<<endl;
			else cout<<symbol<<" - is not print!"<<endl;

			if(isgraph(symbol)) cout<<symbol<<" - is graph!"<<endl;
			else cout<<symbol<<" - is not graph!"<<endl;

			if(isxdigit(symbol)) cout<<symbol<<" - is hexadecimal digit!"<<endl;
			else cout<<symbol<<" - is not hexadecimal digit!"<<endl;
		}

	}while(temp!="end");

	return 0;
}
