//By definition the majorant of an array is a value that
//occur in the least half of the elements of the array.
//Write a program to find the majorant of given array
//(if any). Example:
//{2, 2, 3, 3, 2, 3, 4, 3, 3} -> 3

#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <list>
using namespace std;

typedef multiset<int, less<int> > Ims;

int main() {

	const int SIZE = 9;
	int a[SIZE] = { 2, 2, 3, 3, 2, 3, 4, 3, 3 };
	list <int> list1;
	list1.insert(list1.begin(),a,a+SIZE);
	Ims intMultiset;
	intMultiset.insert(a, a + SIZE);
	ostream_iterator<int> output(cout, " ");
	copy(list1.begin(), list1.end(), output);
	cout << endl;
	Ims::iterator it;
	it = intMultiset.begin();
	unsigned int max=0;
	int numb;
	while (it != intMultiset.end()) {
		if (intMultiset.count(*it) > (intMultiset.size()/2)) {
			if(max < intMultiset.count(*it)){
				max = intMultiset.count(*it);
				numb = *it;
			}

		}
			it = intMultiset.upper_bound(*it);
	}
	copy(list1.begin(), list1.end(), output);
	cout << " -> " << numb << endl;
	return 0;
}
