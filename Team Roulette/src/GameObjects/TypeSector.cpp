/*
 * TypeSector.cpp
 *
 *  Created on: Sep 13, 2014
 *      Author: NandM
 */

#include "TypeSector.h"

namespace GameObjects {

TypeSector::TypeSector(Type type)
	:Sector(){
	this->type = type;
}

TypeSector::~TypeSector() {
	free();
}

Type TypeSector::getType() const {
	return type;
}

bool TypeSector::loadFromFile(SDL_Renderer* gRenderer,
		std::string path) {
	bool success = IRendable::loadFromFile(gRenderer, path);
	string text = getType() == EvenType? "EVEN" : "ODD";
	setRenderedText(gRenderer, text);
	return success;
}

} /* namespace GameObjects */
