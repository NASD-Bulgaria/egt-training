/*
 * Sphere.cpp
 *
 *  Created on: Aug 18, 2014
 *      Author: NandM
 */

#include "Sphere.h"

Sphere::Sphere(double radius) {
	this->setRadius(radius);
}

Sphere::~Sphere() {
	// TODO Auto-generated destructor stub
}

double Sphere::getRadius() const {
	return radius;
}

double Sphere::getArea() {
	return 4 * M_PI * pow(this->getRadius(), 2);
}

double Sphere::getVolume() {
	return (4 * M_PI * pow(this->getRadius(), 3)) / 3;
}

void Sphere::print() {
	cout << "The " << this->getName() << " area with R = " << this->getRadius()
			<< " is " << this->getArea() << " and it's volume is "
			<< this->getVolume();
}

void Sphere::setRadius(double radius) {
	this->radius = radius;
}

string Sphere::getName() {
	return "Sphere";
}
