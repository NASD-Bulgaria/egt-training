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
	// TODO Auto-generated destructor stub
}

short NumberBet::getNumber() {
	return this->number;
}

} /* namespace GameObjects */
