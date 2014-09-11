//============================================================================
// Name        : Ex9_Lecture25.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	ostringstream out;
	string temp;

	do{
		cout<<"Enter string or \"0\" for exit : ";
		cin>>temp;

		if(temp[0]=='b')
			out<<temp<<endl;

	}while(temp!="0");

	cout<<out.str();

	return 0;
}
