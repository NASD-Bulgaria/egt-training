// Exercise 15.12 Solution: Ex15_12.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   double celsius; // holds celsius temperature

   // create column headings with fields of length 20
   cout << setw( 20 ) << "Fahrenheit " << setw( 20 ) << "Celsius\n"
      << fixed << showpoint;

   // convert fahrenheit to celsius and display temperatures
   // showing the sign for celsius temperatures
   for ( int fahrenheit = 0; fahrenheit <= 212; fahrenheit++ )
   {
       celsius = 5.0 / 9.0 * ( fahrenheit - 32 );
       cout << setw( 15 ) << noshowpos << fahrenheit << setw( 23 )
          << setprecision( 3 ) << showpos << celsius << '\n';
   } // end for
} // end main
