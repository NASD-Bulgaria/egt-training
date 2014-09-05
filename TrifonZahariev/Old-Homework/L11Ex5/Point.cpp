/*
 * Point.cpp
 *
 *  Created on: 16.08.2014 ã.
 *      Author: Admin
 */
 #include "Point.h"


	Point::Point(int ax,int ay){
		x = ax;
		y = ay;
	}
	int Point::getX(){
		return x;
	}
	int Point::getY(){
		return y;
	}
	void Point::setX(int ax){
		x = ax;

	}
	void Point::setY( int ay){
		y =ay;
	}


