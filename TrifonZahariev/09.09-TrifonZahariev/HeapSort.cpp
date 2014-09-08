//============================================================================
// Name        : HeapSort.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <conio.h>
using namespace std;

void max_heapify(int *arr, int i, int n) {
	int temp;
	int j;
	temp = arr[i];
	j = 2 * i;
	while (j <= n) {
		if (j < n && arr[j + 1] > arr[j])
			j = j + 1;
		if (temp > arr[j])
			break;
		else if (temp <= arr[j]) {
			arr[j / 2] = arr[j];
			j = 2 * j;
		}
	}
	arr[j / 2] = temp;
	return;
}
void heapsort(int *arr, int n) {
	int temp;
	for (int i = n; i >= 2; i--) {
		temp = arr[i];
		arr[i] = arr[1];
		arr[1] = temp;
		max_heapify(arr, 1, i - 1);
	}
}
void build_maxheap(int *arr, int n) {
	int i;
	for (i = n / 2; i >= 1; i--) {
		max_heapify(arr, i, n);
	}
}
int main() {
	int size;
	cout << "Enter the number of elements of array"<< endl;
	cin >> size;

	int array[size];

	for (int i = 1; i <= size; i++) {
		cout << "Enter element" << (i) << endl;
		cin >> array[i];
	}

	build_maxheap(array, size);
	heapsort(array, size);

	cout << "The sorted output is: "<< endl;
	for (int i = 1; i <= size; i++) {
		cout << array[i] << " ";
	}
}
