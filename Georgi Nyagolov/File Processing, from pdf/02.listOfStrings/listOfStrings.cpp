//============================================================================
// Name        : listOfStrings.cpp
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


int main() {
//	int countRow = 0;
	string newRow;
	vector <string> VectorSort;

	ifstream inFile("Text.txt", ios::in);
	ofstream outFile("NewText.txt", ios::out);

	if ( !inFile ){
		cerr << "File could not be opened Text.txt" << endl;
		exit( 1 );
	} // end if

	if ( !outFile ){
		cerr << "File could not be opened NewText.txt" << endl;
		exit( 1 );
	} // end if

	while(getline(inFile, newRow)){
		VectorSort.push_back(newRow);
	}

	sort(VectorSort.begin(), VectorSort.end());

	for (size_t i = 0; i < VectorSort.size(); ++i) {
		outFile << VectorSort[i] << endl;

	}



	return 0;
}
