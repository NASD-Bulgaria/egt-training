/*
 * RouletteWheel.cpp
 *
 *  Created on: Sep 18, 2014
 *      Author: NandM
 */

#include "RouletteWheel.h"

namespace GameObjects {

RouletteWheel::RouletteWheel() {
	spinSpeed = Stoped;
	spinAngle = 0;
	maxSpinAngle = 0;
	spinInterval = 0;
}

void RouletteWheel::spin() {
	if (spinSpeed != Stoped) {
		if (spinAngle >= maxSpinAngle - ((spinSpeed - 1)* spinInterval)) {
			spinSpeed = static_cast<RouletteWheelState>(spinSpeed - 1);
		}
		spinAngle += spinSpeed / 2.0;
	}
}

RouletteWheel::~RouletteWheel() {
	IRendable::free();
}

RouletteWheelState RouletteWheel::getSpinSpeed() const {
	return spinSpeed;
}

void RouletteWheel::draw(SDL_Renderer* gRenderer) {
	if (mTexture) {
		SDL_RenderCopyEx(gRenderer, mTexture, NULL, &rect, spinAngle, NULL, SDL_FLIP_NONE);
	}
}

double RouletteWheel::getSpinAngle() {
	return spinAngle;
}

void RouletteWheel::initiate() {
	while(spinAngle >= 360){
		spinAngle -= 360;
	}
	maxSpinAngle = spinAngle + (5 * 360) + rand() % 360;
	spinSpeed = VeryFastSpin;
	spinInterval = (maxSpinAngle - spinAngle) / spinSpeed;
}

int RouletteWheel::getRadius() {
	return getWidth()/2;
}

int RouletteWheel::getXCenter() {
	return getX() + getRadius();
}

int RouletteWheel::getYCenter() {
	return getY() + getRadius();
}

} /* namespace GameObjects */

