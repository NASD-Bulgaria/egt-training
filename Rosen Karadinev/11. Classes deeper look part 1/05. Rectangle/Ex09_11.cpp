// Exercise 9.11 Solution: Ex09_11.cpp
#include <iostream> 
#include <iomanip> 
#include "Rectangle.h" // include definition of class Rectangle
using namespace std;

int main()
{
   Rectangle a, b( 4.0, 5.0 ), c( 67.0, 888.0 );
                                                 
   cout << fixed;
   cout << setprecision( 1 );
   
   // output Rectangle a
   cout << "a: length = " << a.getLength() << "; width = " 
      << a.getWidth() << "; perimeter = " << a.perimeter() 
      << "; area = " << a.area() << '\n';

   // output Rectangle b
   cout << "b: length = " << b.getLength() << "; width = " 
      << b.getWidth() << "; perimeter = " << b.perimeter() 
      << "; area = " << b.area() << '\n';

   // output Rectangle c; bad values attempted
   cout << "c: length = " << c.getLength() << "; width = " 
      << c.getWidth() << "; perimeter = " << c.perimeter()
      << "; area = " << c.area() << endl;
} // end main



