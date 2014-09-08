/*
 * Vector.cpp
 *
 *  Created on: 28.08.2014 ã.
 *      Author: Admin
 */

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

void vectorFill(int row, int col, int** arr, vector<int> &elements) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			elements.push_back(arr[i][j]);
		}
	}
}

int main() {

	int ** arr1 = new int*[10];
	for (int o = 0; o < 10; ++o) {
		arr1[o] = new int[5];
	}

	int ** arr2 = new int*[15];
	for (int o = 0; o < 10; ++o) {
		arr2[o] = new int[5];
	}

	srand(time(NULL));

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 5; ++j) {
			arr1[i][j] = rand() % 20;
		}
	}

	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 5; ++j) {
			arr2[i][j] = rand() % 20;
		}
	}

	vector<int> elements;

	vectorFill(10, 5, arr1, elements);
	vectorFill(15, 5, arr2, elements);



	return 0;
}

