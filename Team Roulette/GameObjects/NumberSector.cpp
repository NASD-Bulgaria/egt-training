/*
 * NumberSector.cpp
 *
 *  Created on: Sep 12, 2014
 *      Author: NandM
 */

#include "NumberSector.h"

namespace GameObjects {

NumberSector::NumberSector(short number, Color color, Type type, Half half)
	:Sector(){
	this->number = number;
	this->color = color;
	this->half = half;
	this->type = type;
}

NumberSector::~NumberSector() {
	free();
}

short NumberSector::getNumber() const {
	return number;
}

bool NumberSector::loadFromFile(SDL_Renderer* gRenderer, std::string path) {
	bool success = IRendable::loadFromFile(gRenderer, path);
	stringstream ss;
	ss<< getNumber();
	setRenderedText(gRenderer, ss.str());
	ss.str("");
	ss.clear();
	return success;
}

Color NumberSector::getColor() const {
	return color;
}

Half NumberSector::getHalf() const {
	return half;
}

Type NumberSector::getType() const {
	return type;
}

}
