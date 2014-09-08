//============================================================================
// Name        : PowerOfTwo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <deque>
#include <iterator>
using namespace std;

int main() {
	deque<int> dequeTemp1;
	deque<int> dequeTemp2;
	int array[20] = {3, 4, 4, 2, 1, 3, 4, 3, 6, 8, 3, 4, 6, 2, 1, 3, 4, 10, 6, 8};
	int temp;

	for (int i = 0; i < 20; ++i) {
		dequeTemp1.push_back(array[i]);
	}

	for (int i = 0; i < 20; ++i) {
		temp = dequeTemp1.front();
		if ((temp % 2) != 0) {
			dequeTemp2.push_back(temp);
		}
		dequeTemp1.pop_front();
	}

	for (deque<int>::iterator it = dequeTemp2.begin(); it != dequeTemp2.end(); ++it) {
		cout << *it << " ";
	}

	return 0;
}
