//Using the right-shift operator, the bitwise AND
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
unsigned packedCharacters(char,char);
char unpackFirstChar(unsigned);
char unpackSecondChar(unsigned);

int main() {
	cout << "Enter two characters: ";
	char ch1;
	char ch2;
	cin >> ch1;
	cin >> ch2;

	cout << "The result of bit format of: " << ch1 << endl;
	displayBits( ch1 );
	cout << "\nThe result of bit format of: " << ch2 << endl;
		displayBits( ch2 );
		cout << endl;

	unsigned var = packedCharacters(ch1,ch2);
	cout << "The result of packed characters is: " << ch1 << " " << ch2 << endl;
		displayBits(var);

		cout << "\n Unpack fisrt char: " << char(unpackFirstChar(var)) << endl;
		char x = unpackFirstChar(var);
		displayBits(x);

		cout << "\n Unpack second char: " << char(unpackSecondChar(var)) << endl;
				char y = unpackSecondChar(var);
				displayBits(y);
		return 0;

}

void displayBits (unsigned value )
{
	const int SHIFT = 8 * sizeof(unsigned) -1;
	const unsigned MASK = 1 << SHIFT;

	cout << setw(10) << value << " = ";
	for (int i=1; i<= SHIFT+1;i++)
	{
		cout << ( value & MASK ? '1' : '0' );
		value <<= 1;
		if ( i % 8 == 0 )
			cout << ' ';
	}
	cout << endl;
}
unsigned packedCharacters(char x,char y)
{
	unsigned numb = (x << 8);

	return numb | y;
}

char unpackFirstChar(unsigned x)
{
	unsigned mask = 65280;

		return ((mask & x) >> 8);

}
char unpackSecondChar(unsigned x)
{
	unsigned mask = 255;

			return mask & x;

}
