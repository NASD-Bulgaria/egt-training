/*
 * Triangle.cpp
 *
 *  Created on: 20.08.2014 ã.
 *      Author: Admin
 */
#include "Triangle.h"

Triangle::~Triangle(){

}

double Triangle::getHeight() const {
	return height;
}

void Triangle::setHeight(double height) {
	this->height = height;
}

double Triangle::getSideA() const {
	return sideA;
}

Triangle::Triangle(double sideA, double height) {
	this->sideA = sideA;
	this->height = height;
}

void Triangle::print() {
	cout<< "I'm a rectangle and my area is: "<< getArea()<< endl;
}

double Triangle::getArea() {
	return (sideA*height) / 2;
}

void Triangle::setSideA(double sideA) {
	this->sideA = sideA;
}
