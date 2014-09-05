/*
 * 3DimShapes.h
 *
 *  Created on: 17.08.2014 ã.
 *      Author: Admin
 */

#ifndef TREEDIMSHAPES_H_
#define TREEDIMSHAPES_H_

#include "Shapes.h"


class TreeDimShapes : public Shapes {
public:
	virtual ~TreeDimShapes();
	virtual void print() = 0;
	virtual double getArea() = 0;
	virtual double getVolume() = 0;
};


#endif /* 3DIMSHAPES_H_ */
