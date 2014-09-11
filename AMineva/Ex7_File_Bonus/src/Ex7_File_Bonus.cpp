//============================================================================
// Name        : Ex7_File_Bonus.cpp
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
	string strFile_1;
	string strFile_2;

	ifstream inFile_1("file_1.txt",ios::in);
	if(!inFile_1)
	{
		cout<<"Error opening file!"<<endl;
		return -1;
	}

	ifstream inFile_2("file_2.txt",ios::in);
	if(!inFile_2)
	{
		cout<<"Error opening file!"<<endl;
		return -1;
	}

	int index = 1;
	while(!inFile_1.eof() || !inFile_2.eof())
	{
		getline(inFile_1, strFile_1);
		getline(inFile_2, strFile_2);
		if(strFile_1 == strFile_2) cout<<index<<endl;
		index++;
	}
	inFile_1.close();
	inFile_2.close();

	return 0;
}
