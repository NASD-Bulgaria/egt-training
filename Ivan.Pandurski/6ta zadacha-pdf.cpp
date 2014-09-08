//============================================================================
// Name        : 4ta.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	string str;
	ifstream in("text.txt",ios::in);
	if(!in)
			{
				cout<<" Error"<<endl;
				return -1;
			}
	while(!in.eof())
	{
		string temp;
		getline(in,temp);
		str.append(temp);
	}
	in.close();
	int index=str.find("start");
	cout<<index;
	while(index<str.length())
	{
		str.replace(index,5,"finish");
		index=str.find("start",index+5);

	}
	ofstream out("text.txt",ios::app);
	out<<"\n"<<str;
	out.close();

	return 0;
}
