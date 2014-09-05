//============================================================================
// Name        : File-Ex4.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//Write a program that reads a text file containing a square matrix of numbers and finds in the
//matrix an area of size 2 x 2 with a maximal sum of its elements. The first line in the input file
//contains the size of matrix N. The next N lines contain N numbers separated by space. The
//output should be a in a separate text file – a single number.

#include <iostream>
#include <cstdlib>
using namespace std;

#include <fstream>

int main() {

	int integer;
	int size;

	ifstream inMatrix("matrix.txt", ios::in);
	ofstream outResult("result.txt", ios::out);

	if (!inMatrix && outResult) {
		cerr << "File could not be opened" << endl;
		exit(1);
	}

	while (inMatrix >> integer) {
		size = integer;
		break;
	}
	int matrix[size][size];
	int row = 0;
	int col = 0;

	int maxValue = 0;
	int currValue = 0;

	inMatrix.seekg(1);

	while (inMatrix >> integer) {
		if (col < size) {
			matrix[row][col] = integer;
			col++;
		} else {
			row++;
			col = 0;
			matrix[row][col] = integer;
			col++;
		}
	}

	for (int row = 0; row < size -1;row++)
		{
			for (int col = 0; col < size-1; col++)
			{

				currValue = matrix[row][col] + matrix[row][col+1] + matrix[row+1][col] + matrix[row+1][col+1];
				if (maxValue < currValue)
				{
					maxValue = currValue;
				}
			}

		}
		outResult << maxValue;
		cout << maxValue << endl;

	return 0;
}
