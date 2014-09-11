//============================================================================
// Name        : Ex4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	ifstream in("mesage.txt");
	if(in.is_open())
	{
		getline(in,str);
		in.close();
		int n=ceil(sqrt(str.length()));
		char arr[n][n];
		int index = 0;
		for(int j=0; j<n; j++)
			for(int i=0; i<n; i++)
			{
				if(index<str.length())
					arr[i][j]=str[index];
				else arr[i][j]=' ';
				index++;
			 }
		ofstream out("encoded-message.txt");
		if(out.is_open())
		{
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++)
					out<<arr[i][j];
			out.close();
		}
		else cerr<<"Error opening file!";
	}
	else cerr<<"Error opening file mesage.txt !";
	ifstream read("encoded-message.txt");
	if(read.is_open())
	{
		getline(read,str);
		read.close();
	}
	else cerr<<"Error opening file mesage.txt !";
	cout<<str;
	return 0;
}
