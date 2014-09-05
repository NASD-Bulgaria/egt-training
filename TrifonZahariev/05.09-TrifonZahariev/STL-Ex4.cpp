//============================================================================
// Name        : STL-Ex4.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

int main() {

	int n;

	cout << "Enter N: " << endl;
	cin >> n;

	queue<int> nValues;

	nValues.push(n);

	for (int i = 0; i < 100; ++i) {
		nValues.push(nValues.front() + 1);
		nValues.push(2 * nValues.front() + 1);
		nValues.push(nValues.front() + 2);
		cout << nValues.front() << " ";
		nValues.pop();

	}

	return 0;
}
