/*
 * Cube.h
 *
 *  Created on: 17.08.2014 ã.
 *      Author: Admin
 */

#ifndef CUBE_H_
#define CUBE_H_

#include "TreeDimShapes.h"

class Cube : public TreeDimShapes{
public:
	Cube (double);
	virtual void print();
	virtual double getArea();
	virtual double getVolume();
	~Cube();
	double getSide() const;
	void setSide(double side);

private:
	double side;
};


#endif /* CUBE_H_ */
