//============================================================================
// Name        : RemoveNegative.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <set>
using namespace std;

int main() {
	multiset<int> tempMultiset1;
	multiset<int> tempMultiset2;
	multiset<int> tempMultiset3;
	int array[9] = {3, -4, 4, -2, 1, 3, -4, 3, 2};

	for (int i = 0; i < 9; ++i) {
		tempMultiset1.insert(array[i]);
		tempMultiset3.insert(array[i]);
	}

	for (multiset<int>::iterator it = tempMultiset1.begin(); it != tempMultiset1.end(); ++it){
		if (*it >= 0) {
			tempMultiset2.insert(*it);
		}
	}

	for (multiset<int>::iterator it = tempMultiset2.begin(); it != tempMultiset2.end(); ++it) {
		cout << *it << " ";
	}

	cout << endl;

	for (multiset<int>::iterator it = tempMultiset3.begin(); it != tempMultiset3.end(); ++it){
		if (*it < 0) {
			tempMultiset3.erase(it);
		}
	}

	for (multiset<int>::iterator it = tempMultiset3.begin(); it != tempMultiset3.end(); ++it) {
		cout << *it << " ";
	}

	return 0;
}
