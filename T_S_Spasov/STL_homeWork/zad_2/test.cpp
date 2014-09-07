/*2. Write a method that finds the longest subsequence
 of equal numbers in given array. Use linked list.*/

#include <iostream>
#include <map>
#include <string>

#include <iterator>
#include <list>
using namespace std;

int main() {

	int arr[] = { 1, 2, 5, 6, 3, 3, 1, 4 };

	list<int> seq;

	seq.insert(seq.begin(), arr, arr + sizeof(arr) / sizeof(*arr));
	ostream_iterator<int> out(cout, ", ");
	cout << "The list is: ";
	copy(seq.begin(), seq.end(), out);

	list<int>::iterator it;
	it = seq.begin();
	int curr, next;
	curr = next = *it;
	int count, maxCount;
	count = maxCount = 1;

	while (it != seq.end()) {
		next = *(++it);
		if (curr == next) {
			count++;
		} else {
			if (maxCount < count) {
				maxCount = count;
				count = 1;
			}
		}
		curr = next;
	}

	cout << endl << "The longest sequence is: " << maxCount;
	return 0;
}

