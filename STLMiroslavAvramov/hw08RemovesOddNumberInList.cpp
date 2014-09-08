/* 8. Write a program that removes from a given
sequence all the numbers that present in it odd
number of times. Example:
{4, 2, 2, 5, 2, 3, 2, 3, 1, 5, 2}  {5, 3, 3, 5}*/
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

// a predicate implemented as a function:
//bool odd(const int& value){return (value%2)==0;};

// a predicate implemented as a class:
struct is_odd {
	bool operator()(const int& value) {
		return (value % 2) == 0;
	}
};
int main() {
	const int SIZE = 10;
	int array[SIZE] = { 1, 2, -4, -5, -6, 7, 8, 9, -10, -11 };
	list<int> withoutOdd;
	list<int>::const_iterator iter;

	withoutOdd.insert(withoutOdd.begin(), array, array + SIZE);

		withoutOdd.remove_if(is_odd());



	for (iter = withoutOdd.begin(); iter != withoutOdd.end(); iter++) {
		cout << *iter << endl;

	}
	return 0;
}
