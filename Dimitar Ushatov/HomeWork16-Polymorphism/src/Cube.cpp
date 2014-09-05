/*
 * Cube.cpp
 *
 *  Created on: Aug 18, 2014
 *      Author: NandM
 */

#include "Cube.h"

Cube::Cube(double side) {
	this->setSide(side);
}

Cube::~Cube() {
	// TODO Auto-generated destructor stub
}

double Cube::getSide() const {
	return side;
}

double Cube::getArea() {
	double area = 6 * this->getSide() * this->getSide();
	return area;
}

double Cube::getVolume() {
	double volume = this->getSide() * this->getSide() * this->getSide();
	return volume;
}

void Cube::print() {
	cout << "The " << this->getName() << " area with side = " << this->getSide()
			<< " is " << this->getArea() << " and it's volume is "
			<< this->getVolume();
}

void Cube::setSide(double side) {
	this->side = side;
}

string Cube::getName() {
	return "Cube";
}
