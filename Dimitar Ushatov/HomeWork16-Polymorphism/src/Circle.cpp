/*
 * Circle.cpp
 *
 *  Created on: Aug 18, 2014
 *      Author: NandM
 */

#include "Circle.h"

Circle::Circle(double radius) {
	this->setRadius(radius);
}

Circle::~Circle() {
	// TODO Auto-generated destructor stub
}

double Circle::getRadius() const {
	return radius;
}

double Circle::getArea() {
	return M_PI * this->getRadius() * this->getRadius();
}

void Circle::print() {
	cout << "The " << this->getName() << " area with R = " << this->getRadius()
			<< " is " << this->getArea();
}

void Circle::setRadius(double radius) {
	this->radius = radius;
}

string Circle::getName() {
	return "Circle";
}
