/*
 * Circle.h
 *
 *  Created on: Aug 18, 2014
 *      Author: NandM
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "TwoDimShape.h"

using namespace std;

class Circle: public TwoDimShape {
public:
	Circle(double = 0);

	virtual double getArea();

	virtual void print();

	virtual ~Circle();
	double getRadius() const;
	void setRadius(double radius);
	virtual string getName();

private:
	double radius;
};

#endif /* CIRCLE_H_ */
