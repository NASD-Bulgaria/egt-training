/*
 * Sphere.h
 *
 *  Created on: 17.08.2014 ã.
 *      Author: Admin
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include "TreeDimShapes.h"


class Sphere : public TreeDimShapes{

public:
	Sphere (double);
	virtual void print();
	virtual double getArea();
	virtual double getVolume();
	double getRadius() const;
	void setRadius(double radius);
	virtual ~Sphere();

private:
	double radius;
};

#endif /* SPHERE_H_ */
