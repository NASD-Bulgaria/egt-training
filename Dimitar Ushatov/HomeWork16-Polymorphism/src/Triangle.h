/*
 * Triangle.h
 *
 *  Created on: Aug 18, 2014
 *      Author: NandM
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include "TwoDimShape.h"

class Triangle: public TwoDimShape {
public:
	Triangle(double = 0, double = 0, double = 0);

	virtual double getArea();

	void print();

	virtual ~Triangle();
	double getSideA() const;
	void setSideA(double sideA);
	double getSideB() const;
	void setSideB(double sideB);
	double getSideC() const;
	void setSideC(double sideC);

	virtual string getName();

private:
	double sideA;
	double sideB;
	double sideC;
};

#endif /* TRIANGLE_H_ */
