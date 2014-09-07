#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> shortStack;
	int n, m;
	n = 2;
	m = 10;
	shortStack.push(m);

	while (m > n) {
		if (m % 2 == 0 && m / 2 >= n) {
			m /= 2;
			shortStack.push(m);
			if (m - 1 >= n) {
				m -= 1;
				shortStack.push(m);
			}
		} else {
			if (m - 2 >= n) {
				m -= 2;
				shortStack.push(m);
			} else {
				m -= 1;
				shortStack.push(m);
			}
		}
	}
//	print result
	while (!shortStack.empty()) {
		cout << shortStack.top() << ' ';
		shortStack.pop();
	}
	return 0;
}
