/*
 * Triangle.cpp
 *
 *  Created on: Aug 18, 2014
 *      Author: NandM
 */

#include "Triangle.h"

Triangle::Triangle(double sideA, double sideB, double sideC) {
	this->setSideA(sideA);
	this->setSideB(sideB);
	this->setSideC(sideC);

}

Triangle::~Triangle() {
	// TODO Auto-generated destructor stub
}

double Triangle::getSideA() const {
	return sideA;
}

void Triangle::setSideA(double sideA) {
	this->sideA = sideA;
}

double Triangle::getSideB() const {
	return sideB;
}

void Triangle::setSideB(double sideB) {
	this->sideB = sideB;
}

double Triangle::getSideC() const {
	return sideC;
}

double Triangle::getArea() {
	double p = (this->getSideA() + this->getSideB() + this->getSideC()) / 2;
	double area = sqrt(
			p * (p - this->getSideA()) * (p - this->getSideB())
					* (p - this->getSideC()));
	return area;
}

void Triangle::print() {
	cout << "The " << this->getName() << " area with side A = " << this->getSideA()
			<<", side B = " << this->getSideB() << " and side C = " << this->getSideC()
			<< " is " << this->getArea();
}

void Triangle::setSideC(double sideC) {
	this->sideC = sideC;
}

string Triangle::getName() {
	return "Triangle";
}
