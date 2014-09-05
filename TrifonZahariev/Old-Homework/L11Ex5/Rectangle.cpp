/*
 * Rectangle.cpp
 *
 *  Created on: 16.08.2014 ã.
 *      Author: Admin
 */

#include "Rectangle.h"
#include <iostream>

//topLeft, topRight, bottomLeft, bottomRight
Rectangle::Rectangle(Point tl, Point tr, Point bl, Point br) {
	if( tl.getX() < 20.0 && tl.getY() < 20.0
			&& tr.getY() < 20.0 && tr.getY() < 20.0
			&& bl.getY() < 20.0 && bl.getY() < 20.0
			&& br.getY() < 20.0 && br.getY() < 20.0
	)
	{
		topLeft = tl;
		topRight = tr;
		bottomLeft = bl;
		bottomRight = br;
	}


	else {

		std::cout << "Incorrect Point value for constructor" <<std::endl;
	}

	if( tl.getX() != bl.getX() ) std::cout << "error: Top left and bottom left must have same X value " <<std::endl;
	if( tr.getX() != br.getX() ) std::cout << "error: Top right and bottom right must have same X value " <<std::endl;
}

Point Rectangle::getTopLeft() {
	return topLeft;
}

Point Rectangle::getTopRight() {
	return topRight;
}
Point Rectangle::getBottomLeft() {
	return bottomLeft;
}
Point Rectangle::getBottomRight() {
	return bottomRight;
}

double Rectangle::getWidth() {
	Point tr = this->getTopRight();
	Point tl = this->getTopLeft();
	return tr.getX() - tl.getX();
}

double Rectangle::getHeight() {
	Point p1 = this->getTopRight();
	Point p2 = this->getBottomRight();

	return p1.getY() - p2.getY();

}
double Rectangle::getPerimeter() {
	double per = this->getHeight() * 2 + this->getWidth() * 2;
	return per;
}
double Rectangle::getArea() {
	double area = this->getHeight() * this->getWidth() * 2;
	return area;
}
bool Rectangle::isSquare() {
	if (this->getHeight() == this->getWidth())
		return true;
	else
		return false;
}
