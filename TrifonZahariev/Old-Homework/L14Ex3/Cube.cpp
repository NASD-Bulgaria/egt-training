/*
 * Cube.cpp
 *
 *  Created on: 20.08.2014 ã.
 *      Author: Admin
 */
#include "Cube.h"

double Cube::getSide() const {
	return side;
}

Cube::Cube(double side) {
	this->side = side;
}

void Cube::print() {
	cout << "I'm a cube. My area is: "<< getArea()<< " and my volume is: "<< getVolume()<< endl;
}

double Cube::getArea() {
	return 6*side*side;
}

double Cube::getVolume() {
	return side*side*side;
}

Cube::~Cube() {
}

void Cube::setSide(double side) {
	this->side = side;
}
