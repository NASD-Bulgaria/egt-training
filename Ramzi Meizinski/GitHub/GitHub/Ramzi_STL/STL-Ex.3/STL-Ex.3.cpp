//Write a program that reads N integers from the
//console and reverses them using a stack.

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {

	int n, element;
	stack<int> normal;
	stack<int> reversed;
	cout << "Enter number of integers: ";

	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Enter element " << i + 1 << ": ";
		cin >> element;
		normal.push(element);
	}
	cout << "Original stack is: " << endl;
	while (!normal.empty()) {
		cout << normal.top() << " ";
		reversed.push(normal.top());
		normal.pop();
	}
	cout << "\nReversed stack is: " << endl;
	while (!reversed.empty()) {
		cout << reversed.top() << " ";
		reversed.pop();
	}

	return 0;
}
