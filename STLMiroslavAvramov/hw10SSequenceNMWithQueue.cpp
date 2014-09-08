/* 10. We are given numbers N and M and the following
 operations:
 a) N = N+1
 b) N = N+2
 c) N = N*2
 Write a program that finds the shortest sequence
 of operations from the list above that starts from N
 and finishes in M
 Example: N = 5, M = 16
 Sequence: 5  7  8  16
                          5
           +-----------------------++--------------------------+
           |                        |                          |
           v                        v                          v
         5 6                      5 7                        5 10
    +------++-------+        +------++-------+         +-------+-+---------+
    |       |       |        |       |       |         |         |         |
    v       v       v        v       v       v         v         v         v
5 6 7   5 6 8   5 6 12   5 7 8   5 7 9   5 7 14   5 10 11   5 10 12   5 10 20*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	queue<int> sequence;
	int n;
	int m;
	cout << "Enter number N ";
	cin >> n;
	cout << "Enter number M ";
	cin >> m;


//	sequence.push(n);
//	for (int i = 0; i < m; ++i) {
//		if (n + 1 < m)
//			sequence.push(sequence.front() + 1);
//		if (n + 2 < m)
//			sequence.push(sequence.front() + 2);
//		if (n * n < m)
//			sequence.push(2 * sequence.front() + 1);
//		cout << sequence.front() << ' ';
//		sequence.pop();
//
//	}
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
