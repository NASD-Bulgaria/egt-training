// Fig. 4.11: main.cpp
// Using the bitwise shift operators.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

void displayBits(unsigned); // prototype
void displayBits2(unsigned);
unsigned power2(unsigned, unsigned);
void unpack(unsigned);
int main() {
	unsigned number = 0;
	char first;
	char second;

	cout << "Gimme first char: ";
	cin >> first;
	cout << "Gimme second char: ";
	cin >> second;
	displayBits2(first);
	displayBits2(second);

	number |= first << 8;
	number |= second;
	displayBits(number);
	unpack(number);
	displayBits2('B');
	displayBits2('A');

	return 0;
} // end main

// display bits of an unsigned integer value
void displayBits(unsigned value) {
	const int SHIFT = 8 * sizeof(unsigned) - 1;
	const unsigned MASK = 1 << SHIFT;

	cout << setw(10) << value << " = ";

	// display bits
	for (unsigned i = 1; i <= SHIFT + 1; i++) {
		cout << (value & MASK ? '1' : '0');
		value <<= 1; // shift value left by 1

		if (i % 8 == 0) // output a space after 8 bits
			cout << ' ';
	} // end for

	cout << endl;
} // end function displayBits

void displayBits2(unsigned value) {
	const int SHIFT = 8 * sizeof(char) - 1;
	const unsigned MASK = 1 << SHIFT;

	cout << setw(10) << value << " = ";

	// display bits
	for (unsigned i = 1; i <= SHIFT + 1; i++) {
		cout << (value & MASK ? '1' : '0');
		value <<= 1; // shift value left by 1

		if (i % 8 == 0) // output a space after 8 bits
			cout << ' ';
	} // end for

	cout << endl;
} // end function displayBits
unsigned power2(unsigned number, unsigned pow) {
	return number * (pow << 2);
}
void unpack(unsigned numToChars) {
	char first = 0, second = 0;
	const int SHIFT = 8 * sizeof(char);
	unsigned MASK = 1;

	// display bits
	for (unsigned i = 1; i <= SHIFT+1; i++) {

		first |= (numToChars & MASK);
		MASK = MASK << i;
	} // end for
	cout << endl;
	cout << (char)first;
	MASK = 1;
	numToChars = numToChars >> 8;
	// display bits
	for (unsigned i = 1; i <= SHIFT+1; i++) {

		second |= (numToChars & MASK);
		MASK = MASK << i;
	} // end for
	cout << endl;
	cout << (char)second;


}
