// Exercise 9.11 Solution: Rectangle.cpp
// Member-function definitions for class Rectangle.
#include "Rectangle.h" // include definition of class Rectangle

Rectangle::Rectangle( double w, double l )
{
   setWidth(w); // invokes function setWidth
   setLength(l); // invokes function setLength
} // end Rectangle constructor

void Rectangle::setWidth( double w ) 
{ 
   width = w > 0 && w < 20.0 ? w : 1.0; // sets width
} // end function setWidth

void Rectangle::setLength( double l ) 
{ 
   length = l > 0 && l < 20.0 ? l : 1.0; // sets length 
} // end function setLength

double Rectangle::getWidth() 
{ 
   return width; 
} // end function getWidth

double Rectangle::getLength() 
{
   return length; 
} // end function getLength

double Rectangle::perimeter() 
{ 
   return 2 * ( width + length ); // returns perimeter	
} // end function perimeter

double Rectangle::area() 
{ 
   return width * length; // returns area
} // end function area




