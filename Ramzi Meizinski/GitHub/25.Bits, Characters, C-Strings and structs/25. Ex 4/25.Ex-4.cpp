//============================================================================
// Name        : Ex-4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

void displayBits(unsigned);
unsigned packedCharacters(char,char);
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
