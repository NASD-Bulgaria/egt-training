//5. Make a function that rearranges the order of
//elements in a sequence so that elements that are less
//than or equal to the nth element are placed before
//the nth element. Elements in this group are sorted.
//Other elements are placed after the nth element and
//are not sorted.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void rearrange(vector<int>, int);
int main() {

	srand(time(0));
	vector<int> sequence;

	for (int i = 0; i < 15; i++) {
		sequence.push_back(rand() % 20);
	}

	cout << "write a value: ";
	int number;
	cin >> number;

	rearrange(sequence, number);

	return 0;
}

void rearrange(vector<int> myVector, int value) {

	vector<int> sorted;
	vector<int> unsorted;
	for (unsigned i = 0; i < myVector.size(); i++) {
		if (myVector[i] <= value) {
			sorted.push_back(myVector[i]);
		} else {
			unsorted.push_back(myVector[i]);
		}
	}
	sort(sorted.begin(), sorted.end());

	merge(sorted.begin(), sorted.end(), unsorted.begin(), unsorted.end(),
			myVector.begin());

	for (unsigned i = 0; i < myVector.size(); i++) {
		cout << myVector[i] << " ";
	}

}
