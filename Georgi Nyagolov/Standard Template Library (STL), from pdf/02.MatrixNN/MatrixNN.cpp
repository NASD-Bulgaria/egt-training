//============================================================================
// Name        : MatrixNN.cpp
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

const int SIZE = 5;

int main() {

	string newRow;
	int array[SIZE][SIZE];
	int count = 0;

	ifstream inFile("matrix.txt", ios::in);
	ofstream outFile("NewMatrix.txt", ios::out);

	if (!inFile) {
		cerr << "File could not be opened matrix.txt" << endl;
		exit(1);
	} // end if

	if (!outFile) {
		cerr << "File could not be opened NewMatrix.txt" << endl;
		exit(1);
	} // end if

	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			count++;
			inFile >> newRow;
			array[i][j] = atoi(newRow.c_str());
		}
	}


	for (int sum = 0; sum < 2 * SIZE; ++sum) {
		for (int j = 0; j < SIZE; ++j) {
			for (int i = 0; i < SIZE; ++i) {
				if (i+j == sum) {
					cout << array[i][j] << " ";
					outFile << array[i][j] << " ";
				}
			}
		}
		cout << endl;
		outFile << endl;
	}

	for (int sum = 1-SIZE; sum < SIZE; ++sum) {
		for (int i = SIZE-1; i >= 0; --i) {
			for (int j = SIZE-1; j >= 0; --j) {
				if (i-j == sum) {
					cout << array[i][j] << " ";
					outFile << array[i][j] << " ";
				}
			}
		}
		cout << endl;
		outFile << endl;
	}

	return 0;
}
