/*
 * Sphere.h
 *
 *  Created on: Aug 18, 2014
 *      Author: NandM
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include "ThreeDimShape.h"

class Sphere: public ThreeDimShape {
public:
	Sphere(double = 0);

	virtual double getArea();

	virtual double getVolume();

	virtual void print();

	virtual ~Sphere();
	double getRadius() const;
	void setRadius(double radius);

	virtual string getName();

private:
	double radius;
};

#endif /* SPHERE_H_ */
