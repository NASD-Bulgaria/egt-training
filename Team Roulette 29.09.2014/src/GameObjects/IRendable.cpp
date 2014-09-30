/*
 * IRendable.cpp
 *
 *  Created on: Sep 29, 2014
 *      Author: NandM
 */

#include "IRendable.h"

namespace GameObjects {

IRendable::IRendable(int x, int y, int width, int height) {
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
	mTexture = NULL;
}

IRendable::~IRendable() {
	free();
}

int IRendable::getHeight() const {
	return rect.h;
}

void IRendable::setHeight(int height) {
	this->rect.h = height;
}

int IRendable::getWidth() const {
	return rect.w;
}

void IRendable::setWidth(int width) {
	this->rect.w = width;
}

int IRendable::getX() const {
	return rect.x;
}

void IRendable::setX(int x) {
	this->rect.x = x;
}

int IRendable::getY() const {
	return rect.y;
}

void IRendable::draw(SDL_Renderer* gRenderer) {
	SDL_RenderCopy(gRenderer, mTexture, NULL, &rect );
}

void IRendable::free() {
	if (mTexture) {
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
	}
}

void IRendable::setY(int y) {
	this->rect.y = y;
}

bool IRendable::loadFromFile(SDL_Renderer* gRenderer, std::string path) {
	SDL_Surface * loadedSurface = IMG_Load(path.data());
	mTexture = SDL_CreateTextureFromSurface(gRenderer,loadedSurface);
	this->setWidth(loadedSurface->w);
	this->setHeight(loadedSurface->h);
	SDL_FreeSurface(loadedSurface);
	return mTexture != NULL;
}


bool IRendable::isClicked(int x, int y) {
	if (x >= getX() && x <= getWidth() + getX()
		&& y >= getY() && y <= getY() + getHeight()){
		return true;
	}
	return false;
}
} /* namespace GameObjects */
