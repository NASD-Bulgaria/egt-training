//Write a program that removes from a given sequence all
//numbers which are power of 2.

#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;

bool checkPow(int);

int main() {
	const int SIZE = 12;
	int arr[SIZE] = { 2, 1, 8, 56, 24, 32, 65, 128, 255, 512, 1000, 1024 };
	list<int> list1;
	list<int> result;
	list1.insert(list1.begin(), arr, arr + SIZE);
	list<int>::iterator it;
	cout << "Original array:" << endl;
	ostream_iterator<int> output(cout, " ");
	copy(list1.begin(), list1.end(), output);
	for (it = list1.begin(); it != list1.end(); it++) {
		if (*it % 2 == 0 && *it >= 2) {
			if (checkPow(*it) == 1)
				result.push_back(*it);
		}

	}
	cout << "\n\nOnly numbers which are power of 2: " << endl;
	copy(result.begin(), result.end(), output);
	return 0;
}

bool checkPow(int n) {
	while (!(n % 2)) {
		n /= 2;
	}
	if (n == 1) {
		return true;
	} else {
		return false;
	}
}
