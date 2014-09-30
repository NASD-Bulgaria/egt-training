/*
 * TypeSector.cpp
 *
 *  Created on: Sep 13, 2014
 *      Author: NandM
 */

#include "TypeSector.h"

namespace GameObjects {

TypeSector::TypeSector(Type type) {
	this->type = type;
	this->typeBet = 0;
}

TypeSector::~TypeSector() {
	free();
}

Type TypeSector::getType() const {
	return type;
}

} /* namespace GameObjects */

void GameObjects::TypeSector::placeTypeBet(TypeBet* typeBet) {
		this->typeBet = typeBet;
}

void GameObjects::TypeSector::free() {
	if (typeBet) {
		typeBet->free();
	}
	IRendable::free();
}

void GameObjects::TypeSector::draw(SDL_Renderer* gRenderer) {
	IRendable::draw(gRenderer);

	if (this->typeBet) {
		this->typeBet->setX(
				this->getX()
						+ (this->getWidth() - this->typeBet->getWidth()) / 2);
		this->typeBet->setY(
				this->getY()
						+ (this->getHeight() - this->typeBet->getHeight())
								/ 2);
		this->typeBet->draw(gRenderer);
	}
}
