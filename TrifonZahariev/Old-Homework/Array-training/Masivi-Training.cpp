//============================================================================
// Name        : Masivi-Training.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> chetni(vector<int> array) {
	vector<int> result;
	for (unsigned int i = 0; i < array.size(); ++i) {
		if (array[i] % 2 == 0) {
			result.push_back(array[i]);
		}
	}
	return result;
}

void sort(int * array, int count) {

	int temp;

		for (int a = 0; a < count; a++)
			for (int b = 0; b < count - a - 1; b++) {

				if (array[b] > array[b+1]) {
					temp = array[b];
					array[b] = array[b+1];
					array[b+1] = temp;
				}
			}
}

void sort2(int array[], int count) {

	int temp;

		for (int a = 0; a < count; a++)
			for (int b = 0; b < count - a - 1; b++) {

				if (array[b] > array[b+1]) {
					temp = array[b];
					array[b] = array[b+1];
					array[b+1] = temp;
				}
			}
		for (int i = 0; i < count; ++i) {
			cout << array[i]<< ", ";
		}
}



int main() {

	srand(time(0));
	vector<int> vector1;

	for (int i = 0; i < 50; ++i) {
		vector1.push_back(rand() % 30);
	}

	vector<int> vector2 = chetni(vector1);

	for (unsigned int i = 0; i < vector2.size(); ++i) {
		cout << vector2[i] << ", ";
	}

	int arr[20] = { };
	for (int i = 0; i < 20; ++i) {
		arr[i] = rand() % 50;
	}
	cout << endl;

 sort(arr, 20);

 for (int i = 0; i < 20; i++)
 			cout << arr[i]<<", ";

 cout<< endl;

sort2(arr, 20);

	return 0;
}
