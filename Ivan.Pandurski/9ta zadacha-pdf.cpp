//============================================================================
// Name        : 9ta.cpp
// Author      : Ivan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	string str1;
	string str2;
	int count=0;
	ifstream in("text1.txt",ios::in);
	if(!in)
	{
	cout<<" Error"<<endl;
	return -1;
	}
	ifstream in2("text2.txt",ios::in);
	if(!in2)
	{
	cout<<" Error"<<endl;
	return -1;
	}
	while(!in.eof()&&!in2.eof())
	{
		string temp1, temp2;
		getline(in,temp1);
		str1.append(temp1);
		getline(in2,temp2);
		str2.append(temp2);
		if(str1.compare(str2)!=0)
		{
			count++;
		}

	}
	in.close();
	in2.close();
	cout<<count<<endl;


	return 0;
}
