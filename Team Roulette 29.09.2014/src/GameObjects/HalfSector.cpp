/*
 * HalfSector.cpp
 *
 *  Created on: Sep 13, 2014
 *      Author: NandM
 */

#include "HalfSector.h"

namespace GameObjects {

HalfSector::HalfSector(Half half) {
	this->half = half;
	this->halfBet = 0;
}

HalfSector::~HalfSector() {
	// TODO Auto-generated destructor stub
}

Half HalfSector::getHalf() const {
	return half;
}

void HalfSector::placeHalfBet(HalfBet * halfBet) {
	this->halfBet = halfBet;
}

} /* namespace GameObjects */
