/*2. Write a program that right-shifts an integer variable
4 bits. The program should print the integer in bits
before and after the shift operation.*/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

void displayBits( unsigned ); // prototype

int main()
{
   unsigned number;

   cout<<"Enter a number: ";
   cin>>number;

   // demonstrate bitwise right shift
  cout << "\nThe result before shifting is: ";
  displayBits( number );

   if(number >= 16)
   {
	      cout << "\nThe result after shifting is: ";
	      displayBits( number >> 4 );
   }
   else
	   cout<<"\nThe result is 0";

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


