//============================================================================
// Name        : Array-Exercise.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

bool checkMatrix(int array[6][5]) {
	int countEqual = 0;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (array[i][j] == i * j) {
				countEqual++;
			}
			if (countEqual == 5) {
				return true;
			}
		}
	}
	return false;
}

bool checkMatrix2(int array[6][5]) {
	int countEqual = 0;
	for (int j = 0; j < 5; ++j) {
		for (int i = 0; i < 6; ++i) {
			if (array[i][j] == i + j) {
				countEqual++;
			}
			if (countEqual == 5) {
				return true;
			}
		}
	}
	return false;
}

void printMatrix(int array[6][5]) {
	cout << "The array is: " << endl;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << array[i][j] << " ";

		}
		cout << endl;
	}
}

void printArray(double arr[], int len) {
	cout << "The second array is: " << endl;
	for (int i = 0; i < len - 1; ++i) {
		cout << i << ", ";
	}
}

void findElement(double arr[], int len) {
	for (int i = 0; i < len - 1; ++i) {
		if ((arr[i] + arr[i + 2]) / 2 == arr[i + 1]) {
			cout << endl << "The element at index " << i + 1 << "is = "
					<< "(element with index " << i << " + element of index "
					<< i + 2 << ") / 2" << endl;
		}
	}
}

void countElement(double arr[], int len) {
	int count = 0;
	for (int i = 0; i < len - 1; ++i) {
		if (i == 0 && arr[i] == arr[i + 1]) {
			count++;
		}
		if (i == 5 && arr[i] == arr[i + 1]) {
			count++;
		}
		if ((arr[i] + arr[i + 2]) / 2 == arr[i + 1]) {
			count++;
		}
	}
	cout << "The number of elements that are equal is: " << count << endl;
}

int main() {

	int array[6][5] = { { 3, 5, 2, 1, 9 }, { 0, 1, 2, 3, 4 }, { 12, 15, 16, 17,
			18 }, { 0, 3, 6, 9, 12 }, { 1, 5, 4, 8, 9 }, { 5, 3, 4, 2, 1 } };
	printMatrix(array);
	if (checkMatrix(array) == true) {
		cout << "There is a row that contains elements equal to i * j" << endl;
	} else {
		cout << "There is no row that contains elements equal to i * j" << endl;
	}

	if (checkMatrix2(array) == true) {
			cout << "There is a row that contains elements equal to i + j" << endl;
		} else {
			cout << "There is no row that contains elements equal to i + j" << endl;
		}

	cout << endl;

	double arr[6] = { 1.2, 1.1, 1.4, 1.5, 1.6, 1.9 };
	printArray(arr, 6);
	findElement(arr, 6);
	countElement(arr, 6);

	return 0;
}
