#include <iostream>
#include <iomanip>
#include <cmath>
#include <set>
#include <bitset>
#include <vector>
using namespace std;

int main() {
	const int SIZE = 1024;

	std::bitset<SIZE> sieve; // create bitset of 1024 bits
	sieve.flip(); // flip all bits in bitset sieve
	sieve.reset(0); // reset first bit (number 0)
	sieve.reset(1); // reset second bit (number 1)

	// perform Sieve of Eratosthenes
	int finalBit = sqrt(static_cast<double>(sieve.size())) + 1;

	// determine all prime numbers from 2 to 1024
	for (int i = 2; i < finalBit; i++) {
		if (sieve.test(i)) // bit i is on
				{
			for (int j = 2 * i; j < SIZE; j += i)
				sieve.reset(j); // set bit j off
		} // end if
	} // end for

	vector<int> primeNumbers;
	for (int k = 2; k < SIZE; k++) {
		if (sieve.test(k)) // bit k is on
				{
			primeNumbers.push_back(k);

		} // end for
	}

	set<int> uniqueNums;

	cout << "Enter a number that you want to check: ";
	int n;
	cin >> n;

	int count = 0;
	cout << n << " = ";
	if (n < 0) {
		n *= -1;
	}

	int n2 = n;

	while (n != 1) {
		if (n % primeNumbers[count] == 0) {

			cout << primeNumbers[count];
			n = n / primeNumbers[count];
			if (n != 1) {
				cout << " * ";
			}
			uniqueNums.insert(primeNumbers[count]);
		} else {
			count++;
		}
	}
	cout << endl;
	cout << n2 << " = ";
	for (set<int>::iterator it = uniqueNums.begin(); it != uniqueNums.end();
			it++) {
		cout << *it << " ";
	}

	return 0;
} // end main
