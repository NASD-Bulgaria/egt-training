/*
 * ColorSector.cpp
 *
 *  Created on: Sep 13, 2014
 *      Author: NandM
 */

#include "ColorSector.h"

namespace GameObjects {

ColorSector::ColorSector(Color color)
	:Sector(){
	this->color = color;
}

ColorSector::~ColorSector() {
	free();
}

Color ColorSector::getColor() const {
	return color;
}

bool ColorSector::loadFromFile(SDL_Renderer* gRenderer, std::string path) {
	bool success = IRendable::loadFromFile(gRenderer, path);
	string text = getColor() == RedColor? "RED" : "BLACK";
	setRenderedText(gRenderer, text);
	return success;
}

} /* namespace GameObjects */
