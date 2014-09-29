/*
 * HalfBet.cpp
 *
 *  Created on: Sep 16, 2014
 *      Author: NandM
 */

#include "HalfBet.h"

namespace GameObjects {

HalfBet::HalfBet(Half half, int chipCount)
	:Bet(HalfBet::HalfCoef, chipCount){
	setHalf(half);
}

HalfBet::~HalfBet() {
	// TODO Auto-generated destructor stub
}

Half HalfBet::getHalf() {
	return this->half;
}

void HalfBet::setHalf(Half half) {
	if (half != NoneHalf) {
		this->half = half;
	} else {
		exit(1);
	}
}

} /* namespace GameObjects */
