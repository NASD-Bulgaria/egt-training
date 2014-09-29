/*
 * ColorBet.cpp
 *
 *  Created on: Sep 12, 2014
 *      Author: NandM
 */

#include "ColorBet.h"

namespace GameObjects {

ColorBet::ColorBet(Color betOnColor, int chipCount)
	:Bet(ColorBet::ColorCoef, chipCount){
	setColor(betOnColor);
}

ColorBet::~ColorBet() {
}

Color ColorBet::getColor() {
	return this->betOnColor;
}

void ColorBet::setColor(Color color) {
	if (color == NoneColor) {
		exit(1);
	} else {
		this->betOnColor = color;
	}
}

} /* namespace GameObjects */
