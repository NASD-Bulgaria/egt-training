//============================================================================
// Name        : Ex7_Lecture25.cpp
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
	int sum = 0.0;
	for(int i=0; i<4; i++)
	{
		cout<<"Enter integer value : ";
		cin>>str;
		sum+=atoi(str.c_str());
	}

	cout<<"The sum is : " << sum;
	return 0;
}
