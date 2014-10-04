/*
 * RouletteWheel.cpp
 *
 *  Created on: Sep 18, 2014
 *      Author: NandM
 */

#include "RouletteWheel.h"

namespace GameObjects {

RouletteWheel::RouletteWheel() {
	numbersDegrees[0][1] = 360 / 37.0 / 2.0;
	for (int i = 1; i < 37; ++i) {
		numbersDegrees[i][1] = numbersDegrees[i - 1][1] + 360 / 37.0;
	}
	spinSpeed = Stoped;
	spinTime = 0;
	speedInterval = 0;
	currentNumberIndex = -1;
	currentDegrees = 0;
}

void RouletteWheel::spin() {
	if (currentDegrees > speedInterval * (Stoped - spinSpeed)
			&& spinSpeed != ExtremlySlowSpin) {
		spinSpeed = static_cast<RouletteWheelState>(spinSpeed - 1);
	}
	if (currentDegrees < spinTime) {
		currentDegrees += spinSpeed / 2.0;
	} else {
		while(currentDegrees >= 360){
			currentDegrees -= 360;
		}
		if(currentDegrees >= 360 - (360 / 37.0 / 2.0)){
			currentNumberIndex = 0;
		} else {
			for (int i = 0; i < 36; ++i) {
				if (currentDegrees <= numbersDegrees[i][1]) {
					currentNumberIndex = i;
					break;
				}
			}
		}
		spinSpeed = Stoped;
	}
}

RouletteWheel::~RouletteWheel() {
	// TODO Auto-generated destructor stub
}

double RouletteWheel::numbersDegrees[37][2] = { { 20, 0}, { 1, 0},
		{ 33, 0}, { 16, 0}, { 24, 0}, { 5, 0}, { 10, 0}, { 23, 0},
		{ 8, 0}, { 30, 0}, { 11, 0}, { 36, 0}, { 13, 0}, { 27, 0},
		{ 6, 0}, { 34, 0}, { 17, 0}, { 25, 0}, { 2, 0}, { 21, 0},
		{ 4, 0}, { 19, 0}, { 15, 0}, { 32, 0}, { 0, 0}, { 26, 0},
		{ 3, 0}, { 35, 0}, { 12, 0}, { 28, 0}, { 7, 0}, { 29, 0},
		{ 18, 0}, { 22, 0}, { 9, 0}, { 31, 0}, { 14, 0} };

RouletteWheelState RouletteWheel::getSpinSpeed() const {
	return spinSpeed;
}

short RouletteWheel::getWiningNumber() {
	if (currentNumberIndex != -1) {
		return (short)numbersDegrees[currentNumberIndex][0];
	} else {
		return currentNumberIndex;
	}
}

double RouletteWheel::getCurrentDegrees() {
	return currentDegrees;
}

void RouletteWheel::initiate() {
	srand(time(NULL));
	spinSpeed = VeryFastSpin;
	spinTime = currentDegrees + 1800 + rand() % 360;
	speedInterval = spinTime / VeryFastSpin;
	currentNumberIndex = -1;
}

void RouletteWheel::resetWiningNumber() {
	currentNumberIndex = -1;
}
} /* namespace GameObjects */

