/* 1. Write a program that reads from the console a
 sequence of positive integer numbers. The
 sequence ends when the number 0 is entered.
 Calculate and print the sum and average of the
 elements of the sequence. Use linked list.*/
#include <iostream>
using namespace std;

#include <list>
#include <iterator>
#include <algorithm>

template<typename T> T sumList(const std::list<T> &listRef);
int main() {
	int prom;
	std::list<int> list;
	while (prom != 0) {
		cout << "Enter digit : " << endl;
		cin >> prom;
		list.push_back(prom);
		//cout << prom;
		//sum += prom;

	}

	cout << "The sum is : " << sumList(list) << endl;

	return 0;
}
template < typename T > T sumList( const std::list< T > &listRef )
{
	T sum = 0;
	for (std::list<int>::const_iterator it = listRef.begin(); it != listRef.end(); ++it)
	    sum += *it;
	return sum;
}
