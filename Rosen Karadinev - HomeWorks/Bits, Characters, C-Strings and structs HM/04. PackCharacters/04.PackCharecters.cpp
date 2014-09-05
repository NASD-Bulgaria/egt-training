#include <iostream>
#include <iomanip>
using namespace std;

int packCharacters( char, char );
void displayBits( unsigned );

int main()
{
   char a;
   char b;
   int pack;

   cout << "Enter a character: ";
   cin >> a;

   cout << "Enter another character: ";
   cin >> b;

   cout << "Character " << "\'" << a << "\'" << " represented as bits" << endl;
   displayBits( a );

   cout << "Character " << "\'" << b << "\'"  << " represented as bits" << endl;
   displayBits( b );

   pack = packCharacters( a, b );

   cout << "Packing " << a << " and " << b  << "..." << endl;
   displayBits( pack );
}


int packCharacters( char a, char b )
{
   unsigned pack = a;
   pack <<= 8;
   pack |= b;
   return pack;
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


