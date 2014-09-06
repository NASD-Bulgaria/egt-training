//============================================================================
// Name        : STL-Ex8.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <iterator>
using namespace std;

int main() {

	int array[] = { 4, 2, 2, 5, 2, 3, 2, 3, 1, 5, 2 };

	list<int> elements(array, array + 11);
	set<int> evenElements(array, array + 11);

	for (set<int>::iterator it = evenElements.begin(); it != evenElements.end();
			++it) {
		if (count(array, array + 11, *it) % 2 == 1) {
			elements.remove(*it);
		}
	}

	ostream_iterator<int> output(cout, " ");
	copy(elements.begin(), elements.end(), output);

	return 0;
}
