/*
 * ColorSector.cpp
 *
 *  Created on: Sep 13, 2014
 *      Author: NandM
 */

#include "ColorSector.h"

namespace GameObjects {

ColorSector::ColorSector(Color color) {
	this->color = color;
	colorBet = 0;
}

ColorSector::~ColorSector() {
	// TODO Auto-generated destructor stub
}

Color ColorSector::getColor() const {
	return color;
}

void ColorSector::placeColorBet(ColorBet * colorBet) {
	this->colorBet = colorBet;
}

} /* namespace GameObjects */
