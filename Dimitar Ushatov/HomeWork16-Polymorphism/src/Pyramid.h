/*
 * Pyramid.h
 *
 *  Created on: Aug 18, 2014
 *      Author: NandM
 */

#ifndef PYRAMID_H_
#define PYRAMID_H_

#include "ThreeDimShape.h"

class Pyramid: public ThreeDimShape {
public:
	Pyramid(double = 0, double = 0, double = 0);

	virtual double getArea();

	virtual double getVolume();

	virtual void print();

	virtual ~Pyramid();
	double getBaseSideA() const;
	void setBaseSideA(double baseSideA);
	double getBaseSideB() const;
	void setBaseSideB(double baseSideB);
	double getHeight() const;
	void setHeight(double height);

	virtual string getName();

private:
	double baseSideA;
	double baseSideB;
	double height;
};

#endif /* PYRAMID_H_ */
