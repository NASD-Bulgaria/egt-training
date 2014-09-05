//5. Using the right-shift operator, the bitwise AND
//operator and a mask, write function
//unpackCharacters that takes the unsigned integer
//from Exercise 4 and unpacks it into two characters.
//To unpack two characters from an unsigned twobyte
//integer, combine the unsigned integer with the
//mask 65280 (11111111 00000000) and right-shift the
//result 8 bits. Assign the resulting value to a char
//variable. Then, combine the unsigned integer with
//the mask 255 (00000000 11111111). Assign the result
//to another char variable. The program should print
//the unsigned integer in bits before it is unpacked,
//then print the characters in bits to confirm that they
//were unpacked correctly.

#include <iostream>
#include <iomanip>
using namespace std;

void displayBits(unsigned);
void unpack(unsigned, unsigned);
int main() {
	unsigned number = 0;
	unsigned chars= 'ab';
	unpack(number,chars);
	return 0;

}

void unpack(unsigned number, unsigned chars) {
	char char1;
	char char2;
	unsigned mask = 65280;
	unsigned mask2 = 255;
	number = chars;
	cout << "The unsigned integer before unpacked: " << endl;
	displayBits(number);

	unsigned number2 = number;
	cout << "after unpacked: " << endl;
	number = number & mask;
	number = number >> 8;
	displayBits(number);
	char1 = number;

	number2 = number2 & mask2;
	displayBits(number2);
	char2 = number2;
	cout << "The first char is: " << char1 << endl;
	cout << "The second char is: " << char2 << endl;
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

