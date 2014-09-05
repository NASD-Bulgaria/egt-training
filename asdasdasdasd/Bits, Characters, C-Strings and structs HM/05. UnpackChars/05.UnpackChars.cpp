

#include <iostream>
using namespace std;

void displayBits(unsigned);
void unpack(unsigned, unsigned);

int main()
{
	unsigned number = 0;
	unsigned chars = 'ab';
	unpack(number, chars);
	return 0;
}

void unpack(unsigned number, unsigned chars)
{
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

void displayBits( unsigned value ) // from demo
{
   const int SHIFT = 4 * sizeof( unsigned ) - 1;
   const unsigned MASK = 1 << SHIFT;

   cout <<  value << " = ";

   for ( unsigned c = 1; c <= SHIFT + 1; c++ )
   {
      cout << ( value & MASK ? '1' : '0' );
      value <<= 1;

      if ( c % 4 == 0 )
         cout << ' ';
   } // end for

   cout << endl;
}
