//Write a program that right-shifts an integer variable
//4 bits. The program should print the integer in bits
//before and after the shift operation.

#include <iostream>
#include <iomanip>
using namespace std;

void displayBits(unsigned);

int main() {

	unsigned number = 150;

	cout << "\nThe result of right shifting\n";
	displayBits( number );
	cout << "8 bit positions using the right-shift operator is\n";
	displayBits( number >> 4 );


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
