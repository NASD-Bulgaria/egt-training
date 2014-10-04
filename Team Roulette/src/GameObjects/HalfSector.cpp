/*
 * HalfSector.cpp
 *
 *  Created on: Sep 13, 2014
 *      Author: NandM
 */

#include "HalfSector.h"

namespace GameObjects {

HalfSector::HalfSector(Half half)
	:IRendable(){
	this->half = half;
	this->halfBet = 0;
}

HalfSector::~HalfSector() {
	free();
}

Half HalfSector::getHalf() const {
	return half;
}

void HalfSector::placeHalfBet(HalfBet * halfBet) {
	this->halfBet = halfBet;
}

void GameObjects::HalfSector::free() {
	if (halfBet) {
		halfBet->free();
	}
	IRendable::free();
}

void HalfSector::draw(SDL_Renderer* gRenderer) {
	IRendable::draw(gRenderer);

	if (this->halfBet) {
		this->halfBet->setX(
				this->getX()
						+ (this->getWidth() - this->halfBet->getWidth()) / 2);
		this->halfBet->setY(
				this->getY()
						+ (this->getHeight() - this->halfBet->getHeight())
								/ 2);
		this->halfBet->draw(gRenderer);
	}
}

} /* namespace GameObjects */
