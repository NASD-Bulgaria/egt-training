/*
 * Circle.h
 *
 *  Created on: 17.08.2014 ã.
 *      Author: Admin
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "TwoDimShapes.h"

class Circle : public TwoDimShapes{
private:
	double radius;
public:
	Circle (double);
	virtual void print();
	virtual double getArea();
	double getRadius() const;
	void setRadius(double radius);
	virtual ~Circle();
};

#endif /* CIRCLE_H_ */
