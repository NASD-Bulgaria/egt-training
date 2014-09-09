//============================================================================
// Name        : STL-Algo-Ex3.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

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

	sort(integers.begin(), integers.end());

	ostream_iterator< int > output( cout, " " );

	cout << endl << "Sorted output is: "<< endl;
	copy(integers.begin(), integers.end(), output);

//	for (int i = 0; i < N; ++i) {
//		cout << integers[i] << " ";
//	}

	return 0;
}
