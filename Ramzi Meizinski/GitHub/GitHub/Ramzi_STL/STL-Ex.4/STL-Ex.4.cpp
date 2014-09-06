//We are given the following sequence:
//S1 = N; ->2
//S2 = S1 + 1;->3
//S3 = 2*S1 + 1;->5
//S4 = S1 + 2;->4
//S5 = S2 + 1;->4
//S6 = 2*S2 + 1;->7
//S7 = S2 + 2;->5
//S8 = S3 + 1;->6
//S9 = 2*S3 + 1; ->11
//.....
//Write a program to print its first 100 elements for
//given N. Use the queue class.
//Example: N=2
//Sequence: 2, 3, 5, 4, 4, 7, 5, 6, 11, 7, 5, 9, 6, ...

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {

	queue<int> values;
	int n;

	cout << "Enter N: ";
	cin >> n;
	values.push(n);

	for (int i = 0; i < 100; ++i) {
		values.push(values.front() + 1);
		values.push(2 * values.front() + 1);
		values.push(values.front() + 2);
		cout << values.front() << ' ';
		values.pop();
	}

	return 0;
}
