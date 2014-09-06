//Write a program that reads a sequence of integers ending
//with 0 and sorts them in an increasing order. Use linked
//list.

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {

	list<int> numbers;
	int x;
	do {
		cout << "Enter integer: ";
		cin >> x;
		if (x == 0) {
			break;
		}
		numbers.push_back(x);
	} while (x != 0);

	numbers.sort();
	list<int>::iterator it;
	for (it = numbers.begin(); it != numbers.end(); it++) {

			cout << *it << " ";
		}

	return 0;
}
