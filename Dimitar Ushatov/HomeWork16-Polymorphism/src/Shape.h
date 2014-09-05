/*
 * Shape.h
 *
 *  Created on: Aug 18, 2014
 *      Author: NandM
 */

#ifndef SHAPE_H_
#define SHAPE_H_
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
	Shape();
	virtual void print() = 0;
	virtual ~Shape();
	virtual string getName() = 0;
};

#endif /* SHAPE_H_ */
