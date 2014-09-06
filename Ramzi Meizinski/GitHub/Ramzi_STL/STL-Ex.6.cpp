//Write a program that finds in a given array of integers how
//many times each of them presents.
//Example: array = {3, 4, 4, 2, 3, 3, 4, 3, 2}
//2 -> 2 times
//3 -> 4 times
//4 -> 3 times

#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

typedef multiset< int, less< int > > Ims;

int main() {

	const int SIZE = 15;
	int a[ SIZE ] = { 1,1, 2, 2, 1, 2, 2, 4,3, 4,5,3,4,8,2 };
	Ims intMultiset;
	intMultiset.insert(a, a +SIZE);
	ostream_iterator< int > output( cout, " " );
	copy(intMultiset.begin(),intMultiset.end(),output);
	cout << endl;
	Ims::iterator it;
	it=intMultiset.begin();
	while(it!= intMultiset.end())
	{
		cout << *it << " -> " << intMultiset.count(*it) << " times" << endl;
		it = intMultiset.upper_bound(*it);
	}

	return 0;
}
