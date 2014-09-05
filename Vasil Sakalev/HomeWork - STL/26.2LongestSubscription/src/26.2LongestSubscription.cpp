//2. Write a method that finds the longest subsequence
//of equal numbers in given array. Use linked list.

#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
using namespace std;

int main() {
	int size = 9;
	int arr[size] = { 1, 2, 2, 2, 5, 6, 3, 1, 4 };

	list<int> integers;

	integers.insert(integers.begin(), arr, arr + size);

	int counter = 0;
	int oldInt = arr[0];
	int newInt = 0;
	int theNumber = 0;
	int maxCount;
	for (list<int>::iterator i = integers.begin(); i != integers.end(); i++) {
		newInt = *i;

		if (oldInt == newInt) {
			counter++;
			theNumber = *i;
		}
		if (counter > maxCount) {
			maxCount = counter;
		}
		counter++;
		oldInt = newInt;
	}

	cout << "The longest sequance is  " << maxCount << " of " << theNumber
			<< endl;

	return 0;
}

