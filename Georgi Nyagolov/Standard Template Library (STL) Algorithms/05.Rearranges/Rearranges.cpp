//============================================================================
// Name        : Rearranges.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

int nextNumber();
bool ascending(int, int);

template<typename T>
void eraseFromDeque(deque<T> &, T);

int main() {
	srand(time(NULL));
	deque<int> tempDeque(20);
	deque<int> resultDeque;
	ostream_iterator<int> output(cout, " ");
	int number;
	int count = 0;

	generate(tempDeque.begin(), tempDeque.end(), nextNumber);
	copy(tempDeque.begin(), tempDeque.end(), output);

	cout << endl << "Enter N: ";
	cin >> number;

	eraseFromDeque(tempDeque, number);
	resultDeque.push_back(number);

	for (deque<int>::iterator it = tempDeque.begin(); it != tempDeque.end(); ++it) {
		if (ascending(number, *it)) {
			resultDeque.push_front(*it);
			count++;
		} else {
			resultDeque.push_back(*it);
		}
	}

	sort(resultDeque.begin(), (resultDeque.begin() + count));



	cout << endl;
	copy(resultDeque.begin(), resultDeque.end(), output);

	return 0;
}

int nextNumber() {
	return rand() % 50 + 1;
} // end function

bool ascending(int number, int temp) {
	return (temp <= number);
}

template<typename T>
void eraseFromDeque(deque<T>& tempVector, T value) {
	for (deque<int>::iterator it = tempVector.begin(); it != tempVector.end(); ++it){
		if (*it == value) {
			tempVector.erase(it);
			break;
		}
	}
}
