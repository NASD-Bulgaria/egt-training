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
	// TODO Auto-generated destructor stub
}

Type TypeSector::getType() const {
	return type;
}

} /* namespace GameObjects */

void GameObjects::TypeSector::placeTypeBet(TypeBet* typeBet) {
		this->typeBet = typeBet;
}
