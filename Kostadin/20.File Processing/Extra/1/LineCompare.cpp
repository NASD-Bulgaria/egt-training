//============================================================================
// Name        : LineCompare.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ifstream inFile1( "lines1.txt", ios::in );
	if(!inFile1)
	{
		cerr<< "File could not be opened!"<<endl;
		exit(1);
	}
	ifstream inFile2( "lines2.txt", ios::in );
	if(!inFile2)
	{
		cerr<< "File could not be opened!"<<endl;
		exit(1);
	}

	ofstream endFile("Result.txt", ios::out);
	if(!endFile)
	{
		cerr<< "File could not be opened!"<<endl;
		exit(1);
	}

	vector <bool> res;
	while(!inFile1.eof() && !inFile1.eof())
	{
		string f1;
		string f2;
		getline(inFile1, f1);
		getline(inFile2, f2);
		if(f1.length() != f2.length())
		{
			res.push_back(false);
		}
		else if(f1.length() == f2.length())
		{
			for(int i = 0; i < f1.length(); i++)
			{
				if(f1.at(i) != f2.at(i))
				{
					res.push_back(false);
					break;
				}
			}
			res.push_back(true);
		}

	}
	for(int i = 0; i < res.size(); i++)
	{
		if(res[i] == 1)
		{
			endFile << endl;
		}
		if(res[i] == 0)
		{
			endFile << i + 1 << " line is different"<< endl;
		}
	}
	return 0;
}
