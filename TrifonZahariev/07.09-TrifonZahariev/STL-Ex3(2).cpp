//============================================================================
// Name        : STL-Ex3(2).cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <cmath>
#include <iterator>
using namespace std;

int main() {

	int array[] = { 4, 2, 2, 5, 2, 3, 2, 3, 1, 5, 2, 10, 12, 14 };

	list<int> elements(array, array + 14);
	set<int> evenElements(array, array + 14);

	for (set<int>::iterator it = evenElements.begin(); it != evenElements.end();
			++it) {
		for (set<int>::iterator it2 = evenElements.begin(); it2 != evenElements.end();
				++it2) {
			if (pow(2, *it2) == *it) {
						elements.remove(*it);
					}
		}
	}

	ostream_iterator<int> output(cout, " ");
	copy(elements.begin(), elements.end(), output);

	return 0;
}
