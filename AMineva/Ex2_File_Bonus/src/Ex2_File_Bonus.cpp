//============================================================================
// Name        : Ex2_File_Bonus.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	string str;
	vector<string> sortNames;

	ifstream in("names.txt",ios::in);
	if(!in)
	{
		cout<<"Error opening file!"<<endl;
		return -1;
	}

	ofstream out("sort_names.txt",ios::out);
	if(!out)
	{
		cout<<"Error opening file!"<<endl;
		return -1;
	}

	while(!in.eof())
	{
		getline(in,str);
		sortNames.push_back(str);

	}

	sort(sortNames.begin(),sortNames.end());
	for(int i=0; i<sortNames.size(); i++)
	{
		out<<sortNames[i]<<endl;
	}

	in.close();
	out.close();
	return 0;
}
