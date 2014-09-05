/*
 * Sphere.cpp
 *
 *  Created on: 20.08.2014 ã.
 *      Author: Admin
 */
#include "Sphere.h"


double Sphere::getRadius() const {
	return radius;
}

Sphere::Sphere(double radius) {
	this->radius = radius;
}

void Sphere::print() {
	cout<< "I'm a sphere. My area is: "<< getArea() << " and my volume is: "<< getVolume()<< endl;
}

double Sphere::getArea() {
	return 4*M_PI * radius*radius;
}

double Sphere::getVolume() {
	return 4*M_PI * radius*radius* radius / 3;
}

void Sphere::setRadius(double radius) {
	this->radius = radius;
}

Sphere::~Sphere() {
}
