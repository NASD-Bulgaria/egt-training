//============================================================================
// Name        : File-Ex1.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//
//Write a program that reads a text file and inserts line numbers in front of each line. The
//result should be another text file.

#include <iostream>
using namespace std;
#include <fstream>
#include <cstdlib>
#include <iomanip>

void outputLine(int lineNumber) {
	cout << lineNumber << endl;
}

int main() {

	ofstream outFile("file.txt", ios::out);
	if (!outFile) {
		cerr << "File could not be opened" << endl;
		exit(1);
	}

	cout << "Enter a line numbers" << endl
			<< "Enter end-of-file to end input.\n? ";
	int lineNumber;

	while (cin >> lineNumber) {
		outFile << lineNumber << endl;
		cout << "? ";
	}

	ifstream inFile("file.txt", ios::in);


	while ( inFile >> lineNumber)
	 outputLine(lineNumber);

	return 0;
}
