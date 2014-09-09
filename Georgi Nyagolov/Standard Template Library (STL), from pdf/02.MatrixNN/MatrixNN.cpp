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

int main() {

	string newRow;
	int array[5][5];
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

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			count++;
			inFile >> newRow;
			array[i][j] = atoi(newRow.c_str());
		}
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			cout << array[i - j][j] << " ";
			outFile << array[i - j][j] << " ";
		}
		cout << endl;
		outFile << endl;
	}


	for (int k = 1; k < 5; ++k) {
		int j = k;
		int i = 4;
		while(j<5){
			cout << array[i][j] << " ";
			outFile << array[i][j] << " ";
			j++;
			i--;
		}
		cout << endl;
		outFile << endl;
	}





	return 0;
}
