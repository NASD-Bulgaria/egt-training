//============================================================================
// Name        : SortNames.cpp
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
	ifstream inFile( "Names.txt", ios::in );
	ofstream endFile("SortedNames.txt", ios::out);
	if(!inFile)
	{
		cerr<< "File could not be opened!"<<endl;
		exit(1);
	}
	if(!endFile)
	{
		cerr<< "File could not be opened!"<<endl;
		exit(1);
	}

	vector <string> names;

	while(!inFile.eof())
	{
		string name;
		inFile >> name;
		names.push_back(name);
	}

	for(int i = 0; i < names.size(); i++)
	{
		cout << names[i] << endl;
	}

	sort(names.begin(), names.end());

	int index = 1;
	for(int i = 0; i < names.size(); i++)
	{
		endFile <<index << "." << names[i] << endl;
		index++;
	}
	return 0;
}
