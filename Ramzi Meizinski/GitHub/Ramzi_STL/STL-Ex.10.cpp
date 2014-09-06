//We are given numbers N and M and the following
//operations:
//a) N = N+1
//b) N = N+2
//c) N = N*2
//Write a program that finds the shortest sequence
//of operations from the list above that starts from N
//and finishes in M
//Example: N = 5, M = 16
//Sequence: 5 -> 7 -> 8 -> 16

#include <iostream>
using namespace std;

void shortest(int,int);

int main() {

	int m,n;
	cout << "Enter N: ";
	cin >> n;
	cout << "\nEnter M: ";
	cin >> m;
	cout << m << " ";
	shortest(n,m);

	return 0;
}

void shortest(int n, int m) {
	if (m > n && m / 2 >= n && m % 2 == 0) {
		cout << m / 2 << " ";
		return shortest(n, m / 2);
	} else if ((m - 2) > n && (m - 2) / 2 >= n && (m - 2) % 2 == 0) {
		cout << m - 2 << " ";
		return shortest(n, m - 2);
	} else if ((m - 1) > n && (m - 1) / 2 >= n && (m - 1) % 2 == 0) {
		cout << m - 1 << " ";
		return shortest(n, m - 1);
	} else if ((m - 2) >= n) {
		cout << m - 2 << " ";
		return shortest(n, m - 2);
	} else if ((m - 1) >= n) {
		cout << m - 1 << " ";
		return shortest(n, m - 2);
	}
}





