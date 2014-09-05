/*
 * 2DimShapes.h
 *
 *  Created on: 17.08.2014 ã.
 *      Author: Admin
 */

#ifndef TWODIMSHAPES_H_
#define TWODIMSHAPES_H_

#include "Shapes.h"

class TwoDimShapes : public Shapes {
public:
	virtual void print() = 0;
	virtual double getArea() = 0;
	virtual ~TwoDimShapes();
};


#endif /* 2DIMSHAPES_H_ */
