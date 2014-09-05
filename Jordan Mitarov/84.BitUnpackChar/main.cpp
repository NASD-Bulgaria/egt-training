/*Using the right-shift operator, the bitwise AND
operator and a mask, write function
unpackCharacters that takes the unsigned integer
from Exercise 4 and unpacks it into two characters.
To unpack two characters from an unsigned twobyte
integer, combine the unsigned integer with the
mask 65280 (11111111 00000000) and right-shift the
result 8 bits. Assign the resulting value to a char
variable. Then, combine the unsigned integer with
the mask 255 (00000000 11111111). Assign the result
to another char variable. The program should print
the unsigned integer in bits before it is unpacked,
then print the characters in bits to confirm that they
were unpacked correctly.*/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

void displayBits( unsigned ); // prototype
void unpackCharacters(unsigned);

int main()
{
   unsigned num;

   cout<<"Enter a number : ";
   cin>>num;

   unpackCharacters(num);

   return 0;
} // end main

// display bits of an unsigned integer value
void displayBits( unsigned value )
{
   const int SHIFT = 8 * sizeof( unsigned ) - 1;
   const unsigned MASK = 1 << SHIFT;

   cout << setw( 10 ) << value << " = ";

   // display bits
   for ( unsigned i = 1; i <= SHIFT + 1; i++ ) 
   {
      cout << ( value & MASK ? '1' : '0' );
      value <<= 1; // shift value left by 1

      if ( i % 8 == 0 ) // output a space after 8 bits
         cout << ' ';
   } // end for

   cout << endl;
} // end function displayBits

void unpackCharacters(unsigned num)
{
	char charOne;
	char charTwo;

	cout<<"You entered num: "<<"\""<<num<<"\"" <<" bit is ";
	displayBits(num);
	unsigned resultFirstChar  = num & 65280;
	unsigned resultSecondChar  = num & 255;
	unsigned result = resultFirstChar >> 8;

	charOne = result;
	charTwo = resultSecondChar;

	cout<<"\nCharacter: "<<"\""<<charOne<<"\"";
	displayBits(result);
	cout<<"\nCharacter: "<<"\""<<charTwo<<"\"";
	displayBits(resultSecondChar);

}
