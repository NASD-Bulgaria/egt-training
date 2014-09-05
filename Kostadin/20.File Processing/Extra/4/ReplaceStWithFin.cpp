//============================================================================
// Name        : ReplaceStWithFin.cpp
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
	ifstream inFile( "Start.txt", ios::in );
	if(!inFile)
	{
		cerr<< "File could not be opened!"<<endl;
		exit(1);
	}

	ofstream endFile("Finish.txt", ios::out);
	if(!endFile)
	{
		cerr<< "File could not be opened!"<<endl;
		exit(1);
	}

	string start = "Start";
	string end = "End";
	string fStart = "";

	while(!inFile.eof())
	{
		string fStart;
		getline(inFile, fStart);
		int position = fStart.find( start );
		while ( position != -1 )
		{
			fStart.replace(position, 5 , end);
			position = fStart.find( start , position + 1 );
		}
		endFile << fStart << endl;
	}
	return 0;
}
