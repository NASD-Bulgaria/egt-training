//Write a program that removes from a given sequence all
//the numbers that present in it N number of times.

#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

typedef multiset<int, less<int> > Ims;

int main() {

	cout << "Enter number of times: ";
	unsigned int n;
	cin >> n;

	const int SIZE = 20;
	int a[SIZE] = { 4, 2, 2, 5, 2, 3, 2, 3, 1, 5, 6,5,3,5,7,9,3,1,7,6};
	Ims intMultiset;
	intMultiset.insert(a, a + SIZE);
	ostream_iterator<int> output(cout, " ");
	copy(intMultiset.begin(), intMultiset.end(), output);
	cout << endl;
	Ims::iterator it;
	it = intMultiset.begin();
	while (it != intMultiset.end()) {
		if (intMultiset.count(*it) == n) {
			intMultiset.erase(intMultiset.lower_bound(*it),
					intMultiset.upper_bound(*it));
		} else {
			it = intMultiset.upper_bound(*it);
		}
	}
	copy(intMultiset.begin(), intMultiset.end(), output);
	return 0;
}
