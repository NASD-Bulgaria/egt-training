/*
 * Sector.cpp
 *
 *  Created on: Oct 5, 2014
 *      Author: NandM
 */

#include "Sector.h"

namespace GameObjects {

Sector::Sector() {
	this->bet = NULL;
}

Sector::~Sector() {
	this->free();
}

void Sector::placeBet(Bet* bet) {
	this->bet = bet;
}

void Sector::free() {
	if (this->bet) {
		this->bet->free();
		this->bet = NULL;
	}
	IRendable::free();
}

void Sector::draw(SDL_Renderer* gRenderer) {
	IRendable::draw(gRenderer);

	if (this->bet) {
		this->bet->setPosition(
				this->getX() + (this->getWidth() - this->bet->getWidth()) / 2,
				this->getY() + (this->getHeight() - this->bet->getHeight()) / 2);
		this->bet->draw(gRenderer);
	}
}

} /* namespace GameObjects */
