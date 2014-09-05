/*
 * Circle.cpp
 *
 *  Created on: 20.08.2014 ã.
 *      Author: Admin
 */

#include "Circle.h"

Circle::Circle(double radius){
	this->radius = radius;
}

double Circle::getRadius() const {
	return radius;
}

void Circle::print() {
	cout << "I'm a circle and my area is: " << getArea() << endl;
}

double Circle::getArea() {
	return M_PI * radius * radius;
}

void Circle::setRadius(double radius) {
	this->radius = radius;
}

Circle::~Circle() {
}
