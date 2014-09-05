//============================================================================
// Name        : Matrix.cpp
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
#include <cmath>
using namespace std;


int main() {

	string newRow;
//	vector <string> VectorSort;
	int array[5][5];
	int max = 0;
	int count = 0;

	ifstream inFile("matrix.txt", ios::in);
	ofstream outFile("NewMatrix.txt", ios::out);

	if ( !inFile ){
		cerr << "File could not be opened matrix.txt" << endl;
		exit( 1 );
	} // end if

	if ( !outFile ){
		cerr << "File could not be opened NewMatrix.txt" << endl;
		exit( 1 );
	} // end if

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			count++;
			inFile >> newRow;
			array[i][j] = atoi(newRow.c_str());
		}
	}

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (max<(array[i][j]+array[i][j+1]+array[i+1][j]+array[i+1][j+1])) {
				max = array[i][j]+array[i][j+1]+array[i+1][j]+array[i+1][j+1];
			}
		}
	}

	outFile << sqrt(count) << endl;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			outFile << array[i][j] << " ";
		}
		outFile << endl;
	}
	outFile << max;



	return 0;
}
