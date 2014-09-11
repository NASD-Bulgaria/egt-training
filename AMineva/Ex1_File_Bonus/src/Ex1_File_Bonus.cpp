//============================================================================
// Name        : Ex1_File_Bonus.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int index = 1;
	string str = "";
	ifstream in("line.txt", ios::in);
	if(!in)
	{
		cout<<"Error opening file!"<<endl;
		return -1;
	}

	ofstream out("newLine.txt", ios::out);
	if(!out)
	{
		cout<<"Error opening file!"<<endl;
		return -1;
	}

	while(in.eof())
	{
		getline(in,str);
		out<<index<<". "<<str<<endl;
		index++;
	}

	in.close();
	out.close();

	return 0;
}
