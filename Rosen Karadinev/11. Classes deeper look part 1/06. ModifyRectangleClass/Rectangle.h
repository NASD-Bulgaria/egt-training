// Exercise 9.18 Solution: Rectangle.h
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h" // include definition of class Point

class Rectangle 
{
public:
   // default constructor
   Rectangle( Point = Point( 0.0, 1.0 ), Point = Point( 1.0, 1.0 ),
      Point = Point( 1.0, 0.0 ), Point = Point( 0.0, 0.0 ) );  
   
   // sets x, y, x2, y2 coordinates
   void setCoord( Point, Point, Point, Point );
   double length(); // length
   double width(); // width
   void perimeter(); // perimeter
   void area(); // area
   bool square(); // square
private:
   Point point1; 
   Point point2; 
   Point point3; 
   Point point4; 
}; // end class Rectangle 

#endif



