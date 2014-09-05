//============================================================================
// Name        : RandomIntegers.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include <cstdlib>
#include <ctime>
#include "List.h"

int main() {
	List<int> list;
	int sum;
	double average;
	srand(time(NULL));

	for (int i = 0; i < 25; ++i) {
		list.insertAtBack(rand()%101);
	}

	list.sortList();
	list.print();

	sum = list.sum();
	cout << "The sum is: " << sum << endl;

	average = list.average();
	cout << "The average is: " << fixed << setprecision(2) << average << endl;

	return 0;
}
