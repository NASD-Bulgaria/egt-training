//============================================================================
// Name        : 1va.cpp
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
	int index=1;
	ifstream in("zadacha1.txt",ios::in);
	if(!in)
	{
		cout<<" Error"<<endl;
		return -1;
	}
	ofstream out("newFile.txt",ios::out);
	while(!in.eof())
	{
		getline(in,str);
		out<<index<<". "<<str<<endl;
		index++;
	}
	in.close();
	out.close();




	return 0;
}
