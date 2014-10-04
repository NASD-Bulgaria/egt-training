/*
 * ColorSector.cpp
 *
 *  Created on: Sep 13, 2014
 *      Author: NandM
 */

#include "ColorSector.h"

namespace GameObjects {

ColorSector::ColorSector(Color color)
	:IRendable(){
	this->color = color;
	colorBet = 0;
}

ColorSector::~ColorSector() {
	free();
}

Color ColorSector::getColor() const {
	return color;
}

void ColorSector::placeColorBet(ColorBet * colorBet) {
	this->colorBet = colorBet;
}

void GameObjects::ColorSector::free() {
	if (colorBet) {
		colorBet->free();
	}
	IRendable::free();
}

} /* namespace GameObjects */

void GameObjects::ColorSector::draw(SDL_Renderer* gRenderer) {
	IRendable::draw(gRenderer);

	if (this->colorBet) {
		this->colorBet->setX(
				this->getX()
						+ (this->getWidth() - this->colorBet->getWidth()) / 2);
		this->colorBet->setY(
				this->getY()
						+ (this->getHeight() - this->colorBet->getHeight())
								/ 2);
		this->colorBet->draw(gRenderer);
	}
}
