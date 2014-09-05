//============================================================================
// Name        : STL-Ex3.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <stack>

int main() {

	stack<int> intStack1;
	stack<int> intStack2;
	int n;
	cout << "Enter the numbers one by one (to end press \"0\"): " << endl;

	while (n != 0) {
		cin >> n;
		intStack1.push(n);
	}

	while (!intStack1.empty()) {
		cout << intStack1.top() << " ";
		intStack2.push(intStack1.top());
		intStack1.pop();
	}
	cout << endl;
	while (!intStack2.empty()) {
		cout << intStack2.top() << " ";
		intStack2.pop();
	}

	return 0;
}
