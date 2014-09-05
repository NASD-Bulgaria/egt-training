/*
 * Rectangle.h
 *
 *  Created on: 16.08.2014 ã.
 *      Author: Admin
 */

#ifndef _Paul_Rectangle_H
#define _Paul_Rectangle_H
#include "Point.h"

class Rectangle{
private:
      Point topLeft, topRight, bottomLeft, bottomRight;

public:
	  Rectangle(Point, Point, Point, Point);
      Point getTopLeft();
      Point getTopRight();
      Point getBottomLeft();
      Point getBottomRight();

	  double getHeight();
	  double getWidth();
	  double getPerimeter();
	  double getArea();
	  bool isSquare();
};

#endif /* RECTANGLE_H_ */
