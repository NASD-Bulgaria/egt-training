/*
 * ThreeDimShape.h
 *
 *  Created on: Aug 18, 2014
 *      Author: NandM
 */

#ifndef THREEDIMSHAPE_H_
#define THREEDIMSHAPE_H_

#include "Shape.h"

class ThreeDimShape: public Shape {
public:
	ThreeDimShape();

	virtual double getArea() = 0;

	virtual double getVolume() = 0;

	virtual void print() = 0;

	virtual string getName() = 0;

	virtual ~ThreeDimShape();
};

#endif /* THREEDIMSHAPE_H_ */
