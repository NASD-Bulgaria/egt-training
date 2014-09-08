/*The left-shift operator can be used to pack two
character values into a two-byte unsigned integer
variable. Write a program that inputs two
characters from the keyboard and passes them to
function packCharacters. To pack two characters
into an unsigned integer variable, assign the first
character to the unsigned variable, shift the
unsigned variable left by 8 bit positions and
combine the unsigned variable with the second
character using the bitwise inclusive-OR operator.
The program should output the characters in their
bit format before and after they are packed into the
unsigned integer to prove that they are in fact
packed correctly in the unsigned variable.*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

void displayBits( unsigned ); // prototype
void packCharacters(char ,char );

int main()
{
   char charOne;
   char charTwo;

   cout<<"Enter a char: ";
   cin>>charOne;
   cout<<"Enter a second char: ";
   cin>>charTwo;

   packCharacters(charOne,charTwo);

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

void packCharacters(char charOne,char charTwo)
{
	unsigned shift = charOne;
	unsigned shiftTwo = charTwo;

	cout<<"You entered char: "<<"\""<<charOne<<"\"" <<" bit is ";
	displayBits(shift);
	cout<<"\nYou entered char: "<<"\""<<charTwo <<"\""<<" bit is ";
	displayBits(shiftTwo);
	cout<<"\nThe result is: ";
	unsigned result = shift<<8 | shiftTwo;

	displayBits(result);
}
