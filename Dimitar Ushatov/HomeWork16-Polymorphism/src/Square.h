/*
 * Square.h
 *
 *  Created on: Aug 18, 2014
 *      Author: NandM
 */

#ifndef SQUARE_H_
#define SQUARE_H_
#include "TwoDimShape.h"

class Square: public TwoDimShape {
public:
	Square(double = 0);

	virtual double getArea();

	virtual void print();

	virtual ~Square();

	double getSide() const;

	void setSide(double side);

	virtual string getName();

private:
	double side;
};

#endif /* SQUARE_H_ */
