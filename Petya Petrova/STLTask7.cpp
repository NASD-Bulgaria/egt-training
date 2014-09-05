//7. Write a program that removes from a given sequence all negative numbers.

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <numeric>
#include <vector>

using namespace std;

template<class T> void printVector(T& c);

int main() {

	const int array[] = { -5, 3, 56, -9, 4, 2 };

	// create and initialize vector with above data
	vector<int> numbers(array, array + sizeof(array) / sizeof(array[0]));

	cout << "Numbers from sequence are: " << endl;
	printVector(numbers);

	// transfer to a list and remove all negative numbers
	list<int> listnumber(numbers.begin(), numbers.end());
	listnumber.remove_if(bind2nd(less<int>(), 0));
	cout << "Numbers after remove negative elements are: " << endl;
	printVector(listnumber);

	return 0;
}

template<class T> void printVector(T& c) {
	for (typename T::iterator i = c.begin(); i != c.end(); i++) {
		std::cout << *i << endl;
	}
}

