//============================================================================
// Name        : 2PrintIntegerBits.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

void displayBits(unsigned);

int main() {
	unsigned num = 20;

	cout << "The number is: " << num << " in bits: ";
	displayBits(num);
	cout << "\n right-shift operator with 4 bit positions is: \n";
	displayBits(num >> 4);

	return 0;
}

void displayBits(unsigned value) {
	const int SHIFT = 4 * sizeof(unsigned) - 1;
	const unsigned MASK = 1 << SHIFT;

	cout << setw(10) << value << " = ";

	for (unsigned i = 1; i <= SHIFT + 1; i++) {
		cout << (value & MASK ? '1' : '0');
		value <<= 1;

		if (i % 4 == 0)
			cout << ' ';
	}

	cout << endl;
}
