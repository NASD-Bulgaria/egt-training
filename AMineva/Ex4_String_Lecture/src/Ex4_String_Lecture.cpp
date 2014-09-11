//============================================================================
// Name        : Ex4_String_Lecture.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	string str = "REWOL reppu";

	for(int i=str.length()-1; i>=0; i--)
	{
		if(isupper(str[i])) str[i] = tolower(str[i]);
		else str[i] = toupper(str[i]);
		cout<<str[i];
	}

	return 0;
}
