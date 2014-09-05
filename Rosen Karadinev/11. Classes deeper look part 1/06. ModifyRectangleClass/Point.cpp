// Exercise 9.12 Solution: Point.cpp
// Member-function definitions for class Point.
#include "Point.h" // include definition of class Point

Point::Point( double xCoord, double yCoord )
{
   setX( xCoord ); // invoke function setX
   setY( yCoord ); // invoke function setY
} // end Point constructor

// set x coordinate
void Point::setX( double xCoord )
{
   x = ( xCoord >= 0.0 && xCoord <= 20.0 ) ? xCoord : 0.0;
} // end function setX

// set y coordinate
void Point::setY( double yCoord )
{
   y = ( yCoord >= 0.0 && yCoord <= 20.0 ) ? yCoord : 0.0;
} // end function setY

// return x coordinate
double Point::getX()
{
   return x;
} // end function getX

// return y coordinate
double Point::getY()
{
   return y;
} // end function getY



