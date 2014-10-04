/*
 * NumberSector.cpp
 *
 *  Created on: Sep 12, 2014
 *      Author: NandM
 */

#include "NumberSector.h"

namespace GameObjects {

NumberSector::NumberSector(short number, Color color, Type type, Half half) :
		IRendable(), ColorSector(color), TypeSector(type), HalfSector(half){
	this->number = number;
	this->numberBet = 0;
}

NumberSector::~NumberSector() {
	free();
}

short NumberSector::getNumber() const {
	return number;
}

void NumberSector::placeNumberBet(NumberBet * numberBet) {
	this->numberBet = numberBet;
}

void NumberSector::free() {
	ColorSector::free();
	TypeSector::free();
	HalfSector::free();
	if (numberBet) {
		numberBet->free();
	}
	IRendable::free();
}

void NumberSector::draw(SDL_Renderer* gRenderer) {
	IRendable::draw(gRenderer);
	if (this->numberBet) {
		this->numberBet->setX(
				this->getX()
						+ (this->getWidth() - this->numberBet->getWidth()) / 2);
		this->numberBet->setY(
				this->getY()
						+ (this->getHeight() - this->numberBet->getHeight())
								/ 2);
		this->numberBet->draw(gRenderer);
	}
}

NumberBet* NumberSector::getNumberBet(){
	return numberBet;
}

}
