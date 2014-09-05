/*
 * Pyramid.cpp
 *
 *  Created on: Aug 18, 2014
 *      Author: NandM
 */

#include "Pyramid.h"

Pyramid::Pyramid(double baseSideA, double baseSideB, double height) {
	this->setBaseSideA(baseSideA);
	this->setBaseSideB(baseSideB);
	this->setHeight(height);
}

Pyramid::~Pyramid() {
	// TODO Auto-generated destructor stub
}

double Pyramid::getBaseSideA() const {
	return baseSideA;
}

void Pyramid::setBaseSideA(double baseSideA) {
	this->baseSideA = baseSideA;
}

double Pyramid::getBaseSideB() const {
	return baseSideB;
}

void Pyramid::setBaseSideB(double baseSideB) {
	this->baseSideB = baseSideB;
}

double Pyramid::getHeight() const {
	return height;
}

double Pyramid::getArea() {
	double apexB = sqrt(
			pow(this->getBaseSideA() / 2, 2) + pow(this->getHeight(), 2));
	double apexA = sqrt(
			pow(this->getBaseSideB() / 2, 2) + pow(this->getHeight(), 2));
	double baseArea = this->getBaseSideA() * this->getBaseSideB();
	double firstTriangleArea = (this->getBaseSideA() * apexA) / 2;
	double secondTriangleArea = (this->getBaseSideB() * apexB) / 2;

	return baseArea + (2 * firstTriangleArea) + (2 * secondTriangleArea);
}

double Pyramid::getVolume() {
	double baseArea = this->getBaseSideA() * this->getBaseSideB();
	double volume = (baseArea * this->getHeight()) / 3;
	return volume;
}

void Pyramid::print() {
	cout << "The " << this->getName() << " area with base side A = "
			<< this->getBaseSideA() << ", base side B = " << this->getBaseSideB()
			<< " and Height = " << this->getHeight() << " is " << this->getArea()
			<< " and it's volume is " << this->getVolume();
}

void Pyramid::setHeight(double height) {
	this->height = height;
}

string Pyramid::getName() {
	return "Pyramid";
}
