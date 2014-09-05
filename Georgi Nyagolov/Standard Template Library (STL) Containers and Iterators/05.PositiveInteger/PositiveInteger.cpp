//============================================================================
// Name        : PositiveInteger.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <list>
#include <iterator>
using namespace std;

int sumOfList(list<int> &);
double averageOfList(list<int> &);

int main() {
	int number;
	list<int> list;
	cout << "Enter number: ";
	cin >> number;
	int sum = 0;
	double average = 0.0;

	while (number != 0) {
		list.push_back(number);
		cout << "Enter number: ";
		cin >> number;
	}

	sum = sumOfList(list);
	average = averageOfList(list);

	cout << "Sum is: " << sum << endl;
	cout << "Average is: " << fixed << setprecision(2) << average << endl;

	return 0;
}

int sumOfList(list<int> &tempList) {
	int sum = 0;
	for (list<int>::iterator it = tempList.begin(); it != tempList.end(); ++it) {
		sum += *it;
	}
	return sum;
}

double averageOfList(list<int> &tempList) {
	int counter = 0;
	int sum = 0;
	for (list<int>::iterator it = tempList.begin(); it != tempList.end(); ++it) {
		sum += *it;
		counter++;
	}
	return (double) sum / counter;
}
