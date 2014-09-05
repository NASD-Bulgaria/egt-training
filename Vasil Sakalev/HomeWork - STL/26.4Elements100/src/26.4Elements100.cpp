//4. We are given the following sequence:
//S1 = N;
//S2 = S1 + 1;
//S3 = 2*S1 + 1;
//S4 = S1 + 2;
//S5 = S2 + 1;
//S6 = 2*S2 + 1;
//S7 = S2 + 2;
//...
//Write a program to print its first 100 elements for
//given N. Use the queue class.
//Example: N=2
//Sequence: 2, 3, 5, 4, 4, 7, 5, 6, 11, 7, 5, 9, 6, ...

#include <iostream>
#include <queue>
#include <algorithm>
#include <iterator>
using namespace std;
#define SIZE 5

int main() {

	queue<int> values;
	int number;

	cout << "Enter number ";
	cin >> number;
	values.push(number);

	for (int i = 0; i < 100; ++i) {
		values.push(values.front() + 1);
		values.push(2 * values.front() + 1);
		values.push(values.front() + 2);
		cout << values.front() << ' ';
		values.pop();
	}
	return 0;
}
