/*
 * NumberBet.cpp
 *
 *  Created on: Sep 16, 2014
 *      Author: NandM
 */

#include "NumberBet.h"

namespace GameObjects {

NumberBet::NumberBet(short number, int chipCount)
	:Bet(NumberBet::NumberCoef, chipCount){
	this->number = number;
}

NumberBet::~NumberBet() {
	free();
}

short NumberBet::getNumber() {
	return this->number;
}

void NumberBet::setNumber(short num) {
	if (num >= 0 && num <= 36) {
		this->number = num;
	}
}

} /* namespace GameObjects */
