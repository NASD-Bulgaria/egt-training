/* 5. Write a program that reads a sequence of integers ending
 with 0 and sorts them in an increasing order. Use linked
 list.*/
#include <iostream>
using namespace std;

#include <list>
#include <iterator>
#include <algorithm>

int main() {
	int value;
	list<int> console;
	while (value != 0) {
		cout << "Enter digit : " << endl;
		cin >> value;
		console.push_back(value);
	}

	for (std::list<int>::const_iterator it = console.begin();
			it != console.end(); ++it) {
		cout << *it << ' ';
	}

	cout << "Sorted list : ";
	console.sort();
	for (std::list<int>::const_iterator it = console.begin();
			it != console.end(); ++it) {
			cout << *it << ' ';
	}

	return 0;
}
