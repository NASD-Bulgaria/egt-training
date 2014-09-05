//============================================================================
// Name        : ComparesTextFiles.cpp
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
	string str1;
	string str2;
	int countRow = 1;

	ifstream inFile1("Text.txt", ios::in);
	ifstream inFile2("NewText.txt", ios::in);

	if ( !inFile1 ){
		cerr << "File could not be opened Text.txt" << endl;
		exit( 1 );
	} // end if

	if ( !inFile2 ){
		cerr << "File could not be opened NewText.txt" << endl;
		exit( 1 );
	} // end if

	while(getline(inFile1, str1) && getline(inFile2, str2)){
		if (str1 != str2) {
			cout << countRow << endl;
		}
		countRow++;

	}

	return 0;
}
