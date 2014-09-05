//============================================================================
// Name        : maximalSequence.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <ctime>       /* time */
#include <cstdlib>
#include <vector>
using namespace std;

void maxSequence(const vector<int> &);

int main() {
	srand (time(NULL));
	vector<int> arr;

	for (int i = 0; i < 100; ++i) {
		arr.push_back(1 + rand()%9);
	}

	cout << "Velue: ";
	for (int i = 0; i < 100; ++i) {
		cout << setw(3) << arr[i];
	}

	cout << endl;

	cout << "Index: ";
	for (int i = 0; i < 100; ++i) {
		cout << setw(3) << i;
	}

	maxSequence(arr);

	return 0;
}

void maxSequence(const vector<int> &tempVector){
	int count = 1;
	int maxCount = 0;
	int maxIndex = 0;
	int temp = tempVector[0];

	for (int i = 1; i < 100; ++i) {
		if (temp == tempVector[i]) {
			count++;
			if (count > maxCount) {
				maxCount = count;
				maxIndex = i;
			}
		} else {
			temp = tempVector[i];
			count = 1;
		}
	}

	cout << endl << "Maximum sequence is " << maxCount << ", and end at index: " << maxIndex;
	cout << endl << "The sequance is: ";

	for (int i = maxIndex; i > maxIndex - maxCount; --i) {
		cout << setw(3) << tempVector[i];
	}
}
