//============================================================================
// Name        : MergesTwoOrderedList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

#include "List.h"
using namespace std;

void fillList(List<int> &, int array[], int);

int main() {
	List<int> list1;
	List<int> list2;
	List<int> list3;

	int array1[11] = {1 ,4 ,8 ,11,15,18,19,20,28,32,33};
	int array2[13] = {1 ,2 ,3 ,9 ,10,17,23,25,26,27,39,30,33};

	fillList(list1, array1, 11);
	fillList(list2, array2, 13);

	cout << "List 1: ";
	list1.print();

	cout << "List 2: ";
	list2.print();


	list3.concatenatesList(list1, list2);
	cout << "List 3: ";
	list3.print();

	list3.sortList();
	cout << "Sort List 3: ";
	list3.print();

	return 0;
}

void fillList(List<int> &list, int array[], int size){
	for (int i = 0; i < size; ++i) {
		list.insertAtBack(array[i]);
	}
}
