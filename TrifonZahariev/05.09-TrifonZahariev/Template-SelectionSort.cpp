//============================================================================
// Name        : Template-SelectionSort.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

template<typename T>
void selectionSort(T ptr, int size);

int main() {
	int size;
	cout << "Enter a float arrat's size:" << endl;
	cin >> size;

	float arr1[size];
	double arr2[size];

	srand(time(NULL));

	for (int i = 0; i < size; ++i) {
		arr1[i] = rand() / 0.9f;
		arr2[i] = rand() / 0.9;
	}

	selectionSort(arr1, size);
	for (int i = 0; i < size; ++i) {
		cout << arr1[i] << " ";
	}
cout << endl;
	selectionSort(arr2, size);
	for (int i = 0; i < size; ++i) {
		cout << arr2[i] << " ";
	}

	return 0;
}

template<typename T>
void selectionSort(T ptr, int size) {
	int smallest;


	for (int i = 0; i < size - 1; i++) {
		smallest = i;


		for (int index = i + 1; index < size; index++) {

			if (ptr[index] < ptr[smallest])
				smallest = index;

			swap(ptr[i], ptr[smallest]);
		}
	}
}
