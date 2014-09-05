// Exercise 9.5 Solution: Complex.cpp
// Member-function definitions for class Complex.
#include <iostream> 
#include "Complex.h"
using namespace std;

Complex::Complex( double real, double imaginary )
{ 
   setComplexNumber( real, imaginary ); 
} // end Complex constructor

Complex Complex::add( const Complex &right )
{
   return Complex( 
      realPart + right.realPart, imaginaryPart + right.imaginaryPart );
} // end function add

Complex Complex::subtract( const Complex &right )
{
   return Complex( 
      realPart - right.realPart, imaginaryPart - right.imaginaryPart );
} // end function subtract

void Complex::printComplex()
{
   cout << '(' << realPart << ", " << imaginaryPart << ')';
} // end function printComplex

void Complex::setComplexNumber( double rp, double ip ) 
{
   realPart = rp;
   imaginaryPart = ip;
} // end function setComplexNumber 


