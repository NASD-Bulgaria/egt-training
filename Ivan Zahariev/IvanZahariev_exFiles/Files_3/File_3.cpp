//============================================================================
// Name        : File_3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

//	int countRow = 0;
	string newRow;
	vector < string > vectorSort;

	ifstream inFile("Text.txt", ios::in);
	ofstream outFile("newText.txt", ios::out);
	if (!inFile)
	{
		cerr<<"File (Text.txt) could not be opened!"<<endl;
		exit( 1 );
	}

		if (!outFile)
		{
			cerr<<"File (newText.txt) could not be opened!"<<endl;
			exit( 1 );
		}

		while(getline(inFile, newRow))
		{
//			countRow++;
//			outFile<< countRow << " " << newRow << endl;
			vectorSort.push_back(newRow);
		}
		sort(vectorSort.begin(), vectorSort.end());
		for (size_t i = 0; i < vectorSort.size(); ++i)
		{
//			cout<<vectorSort[i]<<endl;
			outFile << vectorSort[i] << endl;

		}


	return 0;
}
