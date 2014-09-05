/*
 * Rectangle.cpp
 *
 *  Created on: 20.08.2014 ã.
 *      Author: Admin
 */
#include "Rectangle.h"

double Rectangle::getSideA() const {
	return sideA;
}

void Rectangle::setSideA(double sideA) {
	this->sideA = sideA;
}

double Rectangle::getSideB() const {
	return sideB;
}

void Rectangle::setSideB(double sideB) {
	this->sideB = sideB;
}

Rectangle::Rectangle(double sideA, double sideB) {
	this->sideA= sideA;
	this->sideB= sideB;
}

void Rectangle::print() {
	cout<< "I'm a rectangle and my area is: "<< getArea()<< endl;
}

double Rectangle::getArea() {
	return this->sideA*this->sideB;
}

Rectangle::~Rectangle() {
}
