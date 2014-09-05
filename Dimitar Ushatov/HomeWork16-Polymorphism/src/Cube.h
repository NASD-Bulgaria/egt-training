/*
 * Cube.h
 *
 *  Created on: Aug 18, 2014
 *      Author: NandM
 */

#ifndef CUBE_H_
#define CUBE_H_

#include "ThreeDimShape.h"

class Cube: public ThreeDimShape {
public:
	Cube(double = 0);

	virtual double getArea();

	virtual double getVolume();

	virtual void print();

	virtual ~Cube();

	double getSide() const;

	void setSide(double side);

	virtual string getName();

private:
	double side;
};

#endif /* CUBE_H_ */
