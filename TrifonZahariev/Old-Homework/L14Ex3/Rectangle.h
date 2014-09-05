/*
 * Rectangle.h
 *
 *  Created on: 17.08.2014 ã.
 *      Author: Admin
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "FourSide.h"

class Rectangle : public FourSideShape{

public:
	Rectangle (double, double);
	virtual void print();
	virtual double getArea();
	double getSideA() const;
	void setSideA(double sideA);
	double getSideB() const;
	void setSideB(double sideB);
	virtual ~Rectangle();

private:
	double sideA;
	double sideB;
};


#endif /* RECTANGLE_H_ */
