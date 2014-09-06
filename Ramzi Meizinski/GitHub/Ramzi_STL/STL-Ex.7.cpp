//Write a program that removes from a given
//sequence all negative numbers.

#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

typedef multiset< int, less< int > > Ims;

int main() {
	const int SIZE = 15;
	int a[SIZE] = { 1, 1, 2, -1, 1, -2, 2, 4, -1, 4, 5, -10, 4, 8, 2 };
	Ims intMultiset;
	intMultiset.insert(a, a + SIZE);
	ostream_iterator<int> output(cout, " ");
	copy(intMultiset.begin(), intMultiset.end(), output);
	cout << endl;
	Ims::iterator it;
	it = intMultiset.begin();

	while (it != intMultiset.end()) {
		if (*it < 0) {
			intMultiset.erase(*it);
		}
		it++;
		if (*it >= 0) {
			break;
		}

	}
	copy(intMultiset.begin(), intMultiset.end(), output);
	return 0;
}
