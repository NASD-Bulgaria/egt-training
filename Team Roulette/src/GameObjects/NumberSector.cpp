/*
 * NumberSector.cpp
 *
 *  Created on: Sep 12, 2014
 *      Author: NandM
 */

#include "NumberSector.h"

namespace GameObjects {

NumberSector::NumberSector(short number, Color color, Type type, Half half) :
		ColorSector(color), TypeSector(type), HalfSector(half) {
	this->number = number;
	this->numberBet = 0;
	textTexture = NULL;
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

void GameObjects::NumberSector::free() {
	ColorSector::free();
	TypeSector::free();
	HalfSector::free();
	if (numberBet) {
		numberBet->free();
	}
	SDL_DestroyTexture(textTexture);
	textTexture = 0;
	IRendable::free();
}

void NumberSector::draw(SDL_Renderer* gRenderer) {
	IRendable::draw(gRenderer);
	SDL_RenderCopyEx(gRenderer, textTexture , NULL, &textRect, 270, NULL, SDL_FLIP_NONE);
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

} /* namespace GameObjects */

bool GameObjects::NumberSector::loadFromFile(SDL_Renderer* gRenderer,
		string path) {
	IRendable::loadFromFile(gRenderer, path);
	textRect.w = 20;
	textRect.h = 25;
	TTF_Font * font = TTF_OpenFont("Roulette/luximb.ttf", 32);
	SDL_Color color = { 0xFF, 0xFF, 0xFF };
	stringstream ss;
	ss<<(this->number);
	SDL_Surface * lsurf = NULL;
	lsurf = TTF_RenderText_Solid(font, ss.str().c_str(),color);
	textTexture = SDL_CreateTextureFromSurface(gRenderer, lsurf);
	SDL_FreeSurface(lsurf);
	lsurf = NULL;
	TTF_CloseFont(font);
	return true;
}
