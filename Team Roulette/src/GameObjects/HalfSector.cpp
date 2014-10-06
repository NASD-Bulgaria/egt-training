/*
 * HalfSector.cpp
 *
 *  Created on: Sep 13, 2014
 *      Author: NandM
 */

#include "HalfSector.h"

namespace GameObjects {

HalfSector::HalfSector(Half half)
	:Sector(){
	this->half = half;
}

HalfSector::~HalfSector() {
	free();
}

Half HalfSector::getHalf() const {
	return half;
}

void HalfSector::free() {
	Sector::free();
	IRendable::free();
}

bool HalfSector::loadFromFile(SDL_Renderer* gRenderer,
		std::string path) {
	bool success = IRendable::loadFromFile(gRenderer, path);
	string text = getHalf() == LowHalf? "1 - 18" : "19 - 36";
	setRenderedText(gRenderer, text);
	return success;
}
} /* namespace GameObjects */
