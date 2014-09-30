/*
 * TypeBet.cpp
 *
 *  Created on: Sep 12, 2014
 *      Author: NandM
 */

#include "TypeBet.h"

namespace GameObjects {

TypeBet::TypeBet(Type type, int chipCount)
	:Bet(TypeBet::TypeCoef, chipCount){
	setType(type);
}

TypeBet::~TypeBet() {
	free();
}

Type TypeBet::getType() {
	return this->type;
}

void TypeBet::setType(Type type) {
	if (type == NoneType) {
		exit(1);
	} else {
		this->type = type;
	}
}

} /* namespace GameObjects */
