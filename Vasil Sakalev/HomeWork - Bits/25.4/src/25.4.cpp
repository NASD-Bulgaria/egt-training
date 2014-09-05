//4. The left-shift operator can be used to pack two
//character values into a two-byte unsigned integer
//variable. Write a program that inputs two
//characters from the keyboard and passes them to
//function packCharacters. To pack two characters
//into an unsigned integer variable, assign the first
//character to the unsigned variable, shift the
//unsigned variable left by 8 bit positions and     l
//combine the unsigned variable with the second
//character using the bitwise inclusive-OR operator.
//The program should output the characters in their
//bit format before and after they are packed into the
//unsigned integer to prove that they are in fact
//packed correctly in the unsigned variable.

#include <iostream>
#include <iomanip>

using namespace std;

void displayBits(unsigned);
void packCharacters(char, char);

int main() {
	char char1;
	char char2;
	cout << "Write a char: ";
	cin >> char1;

	cout << "Write a second char: ";
	cin >> char2;


	cout << "\nThe char1 in bits\n";
	displayBits(char1);
	cout << "\nThe char1 in bits after shifting left with 8: \n";
	displayBits(char1 << 8);
	cout << "\nThe char2 in bits\n";
	displayBits(char2);
	cout
			<< "cahr1 and char2 using the bitwise inclusive OR operator \"|\" is\n";
	packCharacters(char1, char2);

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
void packCharacters(char first, char second) {
	unsigned num = first << 8;

	displayBits(num | second);

}
