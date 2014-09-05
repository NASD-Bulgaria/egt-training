/*
 * TwoDimShape.h
 *
 *  Created on: Aug 18, 2014
 *      Author: NandM
 */

#ifndef TWODIMSHAPE_H_
#define TWODIMSHAPE_H_

#include "Shape.h"

class TwoDimShape: public Shape {
public:
	TwoDimShape();

	virtual double getArea() = 0;

	virtual void print() = 0;

	virtual ~TwoDimShape();

	virtual string getName() = 0;
};

#endif /* TWODIMSHAPE_H_ */
