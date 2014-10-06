/*
 * IRendable.cpp
 *
 *  Created on: Sep 29, 2014
 *      Author: NandM
 */

#include "IRendable.h"

namespace GameObjects {

IRendable::IRendable(int x, int y) {
	setPosition(x, y);
	setTextRectX(x);
	setTextRectY(y);
	textRect.w = 0;
	textRect.h = 0;
	rect.w = 0;
	rect.h = 0;
	mTexture = NULL;
	textTexture = NULL;
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

int IRendable::getY() const {
	return rect.y;
}

void IRendable::draw(SDL_Renderer* gRenderer, double angle, SDL_Point* center,
		SDL_RendererFlip flip) {
	if (mTexture) {
		SDL_RenderCopyEx(gRenderer, mTexture, NULL, &rect, angle, center, flip);
	}
	if (textTexture) {
		SDL_RenderCopyEx(gRenderer, textTexture, NULL, &textRect, angle, center,
				flip);
	}
}

void IRendable::free() {
	if (mTexture) {
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
	}
	if (textTexture) {
		SDL_DestroyTexture(textTexture);
		textTexture = NULL;
	}
}

void IRendable::setColor(Uint8 red, Uint8 green, Uint8 blue) {
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void IRendable::setBlendMode(SDL_BlendMode blending) {
	SDL_SetTextureBlendMode(mTexture, blending);
}

void IRendable::setAlpha(Uint8 alpha) {
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

bool IRendable::loadFromFile(SDL_Renderer* gRenderer, std::string path) {
	SDL_Surface * loadedSurface = IMG_Load(path.data());
	mTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
	this->setWidth(loadedSurface->w);
	this->setHeight(loadedSurface->h);
	SDL_FreeSurface(loadedSurface);
	loadedSurface = NULL;
	return mTexture != NULL;
}

bool IRendable::isClicked(int x, int y) {
	if (x >= getX() && x <= getWidth() + getX() && y >= getY()
			&& y <= getY() + getHeight()) {
		return true;
	}
	return false;
}

void IRendable::setPosition(int x, int y) {
	int xOffset = this->textRect.x - this->rect.x;
	int yOffset = this->textRect.y - this->rect.y;
	this->rect.x = x;
	this->rect.y = y;
	this->textRect.x = x + xOffset;
	this->textRect.y = y + yOffset;
}

void IRendable::setTextRectX(int x) {
	textRect.x = x;
}

void IRendable::setTextRectY(int y) {
	textRect.y = y;
}

int IRendable::getTextRectX() {
	return textRect.x;
}

int IRendable::getTextRectY() {
	return textRect.y;
}

void IRendable::setRenderedText(SDL_Renderer* gRenderer,
		string text, int size, Uint8 r, Uint8 g, Uint8 b, string fontPath ) {
	SDL_Surface * loadedSurface = NULL;
	TTF_Font * font = TTF_OpenFont(fontPath.c_str(), size);
	if (textTexture != NULL) {
		SDL_DestroyTexture(textTexture);
		textTexture = NULL;
	}
	SDL_Color color = { r, g, b };
	loadedSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	textTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
	TTF_CloseFont(font);
	font = NULL;
	SDL_FreeSurface(loadedSurface);
	loadedSurface = NULL;
	setTextRectX(getX() + (getWidth() - text.length() * size / 2) / 2);
	setTextRectY(getY() + (getHeight() - size ) / 2);
	textRect.w = text.length() * size/2;
	textRect.h = size;
}

void IRendable::setTextRectW(int w) {
	textRect.w = w;
}

void IRendable::setTextRectH(int h) {
	textRect.h = h;
}

} /* namespace GameObjects */

