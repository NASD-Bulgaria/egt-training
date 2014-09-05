/*
 * Square.cpp
 *
 *  Created on: Aug 18, 2014
 *      Author: NandM
 */

#include "Square.h"
using namespace std;

Square::Square(double side) {
	// TODO Auto-generated constructor stub
	this->setSide(side);
}

double Square::getArea() {
	return this->getSide() * this->getSide();
}

void Square::print() {
	cout << "The " << this->getName() << " area with side = " << this->getSide()
			<< " is " << this->getArea();
}

Square::~Square() {
	// TODO Auto-generated destructor stub
}

double Square::getSide() const {
	return side;
}

string Square::getName() {
	return "Square";
}

void Square::setSide(double side) {
	this->side = side;
}
