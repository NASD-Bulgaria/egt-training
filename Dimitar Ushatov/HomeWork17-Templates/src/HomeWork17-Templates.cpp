//============================================================================
// Name        : HomeWork17-Templates.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Array.h"
#include "Array.cpp"
using namespace std;

template<typename T>
void sortArray(T* array, int count);

template<typename T>
int printArray(const T* array, int count, int lowSubscript, int highSubscript);

template<typename T>
int printArray(const T* array, int size);

void solveFirstAndSecond();

template<typename T>
bool isEqual(T &first, T &second);

void fourthTask();

void solveTask5();

int main() {
//	solveFirstAndSecond();
	fourthTask();
	return 0;
}

void solveFirstAndSecond() {
	const int size = 5;
	int lowSubscript = 0;
	int highSubscript = 2;
	int intArray[size] = { 1, 5, 3, 8, 10 };
	float floatArray[size] = { 1.2, 6.5, 3.4, 7.9, 0.2 };

	cout << "Int Array:" << endl;
	int count = printArray(intArray, size);
	cout << "Total number of elements: " << count << endl;
	cout << "Int Array in range " << lowSubscript << " and " << highSubscript
			<< ":" << endl;
	count = printArray(intArray, size, 0, 2);
	cout << "The count of elements in range " << lowSubscript << " and "
			<< highSubscript << " is " << count << endl;
	cout << endl;

	cout << "Float Array:" << endl;
	count = printArray(floatArray, size);
	cout << "Total number of elements: " << count << endl;
	cout << "Float Array in range " << lowSubscript << " and " << highSubscript
			<< ":" << endl;
	count = printArray(floatArray, size, 0, 2);
	cout << "The count of elements in range " << lowSubscript << " and "
			<< highSubscript << " is " << count << endl;
	cout << endl;

	sortArray(intArray, size);
	sortArray(floatArray, size);

	cout << "Sorted Int Array:" << endl;
	count = printArray(intArray, size);
	cout << "The count of elements is " << count << endl;
	cout << endl;

	cout << "Sorted Float Array:" << endl;
	count = printArray(floatArray, size);
	cout << "The count of elements is " << count << endl;
	cout << endl;
}

void fourthTask(){
	int a = 5;
	int b = 5;
	cout << a << " is equal to " << b << ": "
			<< (isEqual(a, b) ? "True" : "False") << endl;

	double c = 6.7;
	double d = 7.6;

	cout << c << " is equal to " << d << ": "
			<< (isEqual(c, d) ? "True" : "False") << endl;
}

template<typename T>
void sortArray(T* array, int count) {
	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if (array[i] > array[j]) {
				T tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}

template<typename T>
int printArray(const T* array, int size, int lowSubscript, int highSubscript) {
	if (lowSubscript < 0 || lowSubscript > size - 1 || highSubscript < 0
			|| highSubscript > size - 1 || highSubscript == lowSubscript) {
		return 0;
	}
	int count = 0;
	cout << "The array elements between array[" << lowSubscript
			<< "] and array [" << highSubscript << "] are:" << endl;
	for (int i = lowSubscript; i <= highSubscript; ++i) {
		cout << array[i] << (i == highSubscript ? "\n" : ", ");
		count++;
	}
	return count;
}

template<typename T>
int printArray(const T* array, int size) {
	cout << "The array elements are:" << endl;
	for (int i = 0; i < size; ++i) {
		cout << array[i] << (i == size - 1 ? "\n" : ", ");
	}
	return size;
}

template<typename T>
bool isEqual(T &first, T &second) {
	if (first == second) {
		return true;
	} else {
		return false;
	}
}

void solveTask5(){
	Array<float> array(5);
}
