//============================================================================
// Name        : .cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

void displayBits(unsigned);
int power(int, int);

int main() {

	int numb = 20;
	int powerrr = 4;

	cout << "The result as integer is: " << power(numb,powerrr);
	cout << "\nThe result as bits is: \n";
	displayBits( power(numb,powerrr) );



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
int power(int number, int pow)
{

	return number * (2 << (pow-1));
}
