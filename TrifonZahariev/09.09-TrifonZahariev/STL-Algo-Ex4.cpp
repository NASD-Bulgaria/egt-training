//============================================================================
// Name        : STL-Algo-Ex4.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//4.  Write a program that generates a random number
//sequence and finds the first 3 elements in descending
//order.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
	srand(time(NULL));
	vector<int> integers;
	int N;
	cout << "Enter the number of integers to be generated: " << endl;
	cin >> N;

	cout << "Unsorted integers are: "<< endl;
	for (int i = 0; i < N; ++i) {
		integers.push_back(rand() % 100);
		cout << integers[i] << " ";
	}

	sort(integers.rbegin(), integers.rend());

	ostream_iterator< int > output( cout, " " );

	cout << endl << "Sorted output is: "<< endl;
	copy(integers.begin(), integers.end(), output);

	cout << endl << "First 3 unique elements in descending order are: " << endl;
	for (int i = 0; i < 3; ++i) {
		if (integers[i] == integers[i + 1]){
			integers.erase(integers.begin(), integers.begin() + (i +1));
			cout << integers[i] << " ";
		} else {
			cout << integers[i] << " ";
		}
	}

	return 0;
}
