//============================================================================
// Name        : STL-Ex10.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	int m;

	cout << "Enter n: " << endl;
	cin >> n;
	cout << endl << "Enter m: " << endl;
	cin >> m;

	stack<string> values;

	while (m != n) {
		if (m % 2 != 0) {
			m = m - 1;
			values.push("N + 1");
		}
		if (m / 2 > n) {
			m = m / 2;
			values.push("N * 2");
			if (m == n) {
				break;
			}
		}
		if (m < n * 2) {
			m = m - 2;
			values.push("N + 2");
			if (m - 1 == n) {
				m = m - 1;
				values.push("N + 1");
			}
		}
	}

	while(!values.empty()){
		cout << values.top() << endl;
		values.pop();
	}

	return 0;
}
