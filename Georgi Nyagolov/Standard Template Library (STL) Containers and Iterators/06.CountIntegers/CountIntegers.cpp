//============================================================================
// Name        : CountIntegers.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main() {
	int counter = 0;
	int temp;
	multiset<int> tempMultiset;
	int array[9] = {3, 4, 4, 2, 2, 2, 4, 3, 2};

	for (int i = 0; i < 9; ++i) {
		tempMultiset.insert(array[i]);
	}

	multiset<int>::iterator it;
	temp = *tempMultiset.begin();

	for (it = tempMultiset.begin(); it != tempMultiset.end(); ++it) {
		if (temp == *it) {
			temp = *it;
			counter++;
		} else {
			cout << temp << "->" << counter << endl;
			counter = 1;
			temp = *it;
		}
	}

	cout << temp << "->" << counter << endl;

	return 0;
}
