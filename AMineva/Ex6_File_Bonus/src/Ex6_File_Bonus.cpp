//============================================================================
// Name        : Ex6_File_Bonus.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	string str;

	ifstream in("text.txt",ios::in);
	if(!in)
	{
		cout<<"Error opening file!"<<endl;
		return -1;
	}
	while(!in.eof())
	{
		string temp;
		getline(in,temp);
		str.append(temp);
	}
	in.close();

	int index = str.find(" test");
	while(index < str.length())
	{
		if(isalpha(str[index+5]) || isdigit(str[index+5]) || str[index+5]=='_')
		{
			str.erase(index, 1);
			while(!isspace(str[index])) str.erase(index, 1);
		}
		index=str.find(" test", ++index);

	}

	ofstream out("text.txt",ios::app);
	if(!out)
	{
		cout<<"Error opening file!"<<endl;
		return -1;
	}
	out<<"\n"<<str;
	out.close();

	return 0;
}
