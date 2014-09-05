/*
 * Right.h
 *
 *  Created on: 17.08.2014 ã.
 *      Author: Admin
 */

#ifndef RIGHT_H_
#define RIGHT_H_

#include "Triangle.h"
#include "Equilateral.h"
#include "Scalene.h"

class Right : public Triangle, public Equilateral, public Scalene{

};


#endif /* RIGHT_H_ */
