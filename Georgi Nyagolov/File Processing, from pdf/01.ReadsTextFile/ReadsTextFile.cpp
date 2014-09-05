//============================================================================
// Name        : ReadsTextFile.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;


int main() {
	int countRow = 0;
	string newRow;

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
		countRow++;
		outFile << countRow << " " << newRow << endl;

//		cout << newRow << endl;
//		break;
	}



	return 0;
}
