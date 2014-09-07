//============================================================================
// Name        : 1(2).cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <numeric>
#include<list>
#include <exception>
using namespace std;

#include <iterator>

template<typename T>
void printSequence(const list<T> &arrIntegersRef);

int main() {
	srand(time(NULL));
	int size;
	cout << "Enter the size of the array: " << endl;
	cin >> size;
	int arr[size];

	for (int i = 0; i < size; ++i) {
		arr[i] = rand() % 5;
	}

	list<int> arrIntegers(arr, arr + size);


	printSequence(arrIntegers);

	int countEqual = 0;
	int maxEqual = 0;
	int value = 0;
	int maxValue = 0;
	int currIt;

	list<int> :: iterator it;

	it = arrIntegers.begin();

	int element = *it;

	for(it = arrIntegers.begin(); it != arrIntegers.end(); ++it) {

		if(*it == element){
			countEqual++;
			value += *it;
			if(value > maxValue){
				maxValue = value;
				currIt = *it;
			}
		} else {
			countEqual = 1;
			value = 0;
		}
		if(countEqual > maxEqual){
			maxEqual = countEqual;
		}
		element = *it;
	}
	cout << "The max subsequence of integers is " << maxEqual << " with max value of "<< maxValue + currIt << endl;

	return 0;
}

template<typename T>
void printSequence(const list<T> &arrIntegersRef){
	if (arrIntegersRef.empty())
		cout << "List is empty";
	else {
		ostream_iterator<T> output(cout, " ");
		copy(arrIntegersRef.begin(), arrIntegersRef.end(), output);

	}
}

