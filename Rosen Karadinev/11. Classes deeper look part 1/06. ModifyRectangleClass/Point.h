// Exercise 9.12 Solution: Point.h
#ifndef POINT_H
#define POINT_H

class Point 
{
public:
   Point( double = 0.0, double = 0.0 ); // default constructor
   
   // set and get functions
   void setX( double );
   void setY( double );
   double getX(); 
   double getY(); 
private:
   double x; // 0.0 <= x <= 20.0
   double y; // 0.0 <= y <= 20.0
}; // end class Point 

#endif

