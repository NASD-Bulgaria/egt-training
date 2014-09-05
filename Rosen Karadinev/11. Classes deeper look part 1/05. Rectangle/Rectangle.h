// Exercise 9.11 Solution: Rectangle.h
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle 
{
public:
   Rectangle( double = 1.0, double = 1.0 ); // default constructor
   void setWidth( double w ); // set width
   void setLength( double l ); // set length
   double getWidth(); // get width
   double getLength(); // get length  
   double perimeter(); // perimeter
   double area(); // area
private:
   double length; // 1.0 < length < 20.0
   double width; // 1.0 < width < 20.0
}; // end class Rectangle

#endif


