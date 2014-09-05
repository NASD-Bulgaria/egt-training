/*
 * Triangle.h
 *
 *  Created on: 17.08.2014 ã.
 *      Author: Admin
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "TreeSide.h"

class Triangle : public TreeSideShape {
public:
	Triangle(double, double);
	virtual void print();
	virtual double getArea();
	virtual ~Triangle();
	double getHeight() const;
	void setHeight(double height);
	double getSideA() const;
	void setSideA(double sideA);

private:
	double sideA;
	double height;
};


#endif /* TRIANGLE_H_ */
