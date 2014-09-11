//============================================================================
// Name        : Ex2_String_Lectire.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	string str[5];
	istringstream inputString("something play anything player other");
	ostringstream outputString;
	for(int i=0; i<5; i++)
	{
		inputString >> str[i];
		int index = str[i].length();
		if(str[i].compare(index-1, 1, "r")==0 || str[i].compare(index-2, 2, "ay")==0) outputString << str[i] <<endl;
	}

	cout<<outputString.str();

	return 0;
}
