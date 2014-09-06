// Fig. 4.11: main.cpp
// Using the bitwise shift operators.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

void displayBits( unsigned ); // prototype
unsigned power2(unsigned, unsigned);
int main()
{
   unsigned number;
//   cout << "Gimme the number: ";
//cin >> number;


number = power2(5,2);
displayBits(2);
displayBits( number );

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

unsigned power2(unsigned number, unsigned pow){
	return number*(pow<<2);
}
