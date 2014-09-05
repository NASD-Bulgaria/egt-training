// Exercise 11.8 Solution: ex11_08.cpp
// Complex class test program.
#include <iostream>
#include "Complex.h"
using namespace std;

int main()
{
   Complex x, y( 4.3, 8.2 ), z( 3.3, 1.1 ), k;

   cout << "Enter a complex number in the form: (a, b)\n? ";
   cin >> k; // demonstrating overloaded >>
   cout << "x: " << x << "\ny: " << y << "\nz: " << z << "\nk: "
      << k << '\n'; // demonstrating overloaded <<
   x = y + z; // demonstrating overloaded + and =
   cout << "\nx = y + z:\n" << x << " = " << y << " + " << z << '\n';
   x = y - z; // demonstrating overloaded - and =
   cout << "\nx = y - z:\n" << x << " = " << y << " - " << z << '\n';
   x = y * z; // demonstrating overloaded * and =
   cout << "\nx = y * z:\n" << x << " = " << y << " * " << z << "\n\n";

   if ( x != k ) // demonstrating overloaded !=
      cout << x << " != " << k << '\n';

   cout << '\n';
   x = k;

   if ( x == k ) // demonstrating overloaded ==
      cout << x << " == " << k << '\n';
} // end main

