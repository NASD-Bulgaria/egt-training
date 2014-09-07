//============================================================================
// Name        : NandM.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
	int n;
	int m;
	stack<int> tempStack;

	cout << "Enter N(N<M): ";
	cin >> n;
	cout << "Enter M(N<M): ";
	cin >> m;
	while (n > m) {
		cout << "Enter N(N<M): " << endl;
		cin >> n;
		cout << "Enter M(N<M): " << endl;
		cin >> m;
	}

	tempStack.push(m);

	while (n != m) {
		if (m / 2 == n && m % 2 == 0) {
			tempStack.push(n);
			break;
		}
		if (m - 4 == n) {
			tempStack.push(m = m - 2);
			tempStack.push(m - 2);
			break;
		}
		if (m - 3 == n) {
			tempStack.push(m = m - 2);
			tempStack.push(m - 1);
			break;
		}
		if (m - 2 == n) {
			tempStack.push(m - 2);
			break;
		}
		if (m - 2 == n) {
			tempStack.push(m - 1);
			break;
		}

		if (m % 2 == 1) {
			tempStack.push(m = m - 1);
		} else {
			tempStack.push(m = m / 2);
		}
	}

	while (!tempStack.empty()) {
		cout << tempStack.top() << " "; // view (and display) top element
		tempStack.pop(); // remove top element
	}
	return 0;
}


