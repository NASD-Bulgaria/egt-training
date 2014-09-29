/*
 * NumberSector.cpp
 *
 *  Created on: Sep 12, 2014
 *      Author: NandM
 */

#include "NumberSector.h"

namespace GameObjects {

NumberSector::NumberSector(short number, Color color, Type type, Half half)
	:ColorSector(color), TypeSector(type), HalfSector(half){
	this->number = number;
	this->numberBet = 0;
}

NumberSector::~NumberSector() {
	// TODO Auto-generated destructor stub
}

short NumberSector::getNumber() const {
	return number;
}

void NumberSector::placeNumberBet(NumberBet * numberBet) {
	this->numberBet = numberBet;
}

} /* namespace GameObjects */
