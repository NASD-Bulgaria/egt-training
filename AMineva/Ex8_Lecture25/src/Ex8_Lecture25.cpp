//============================================================================
// Name        : Ex8_Lecture25.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
	string str;
	double sum = 0.0;
	for(int i=0; i<4; i++)
	{
		cout<<"Enter double value : ";
		cin>>str;
		sum+=atof(str.c_str());
	}

	cout<<"The sum is : " << sum;

	return 0;
}
