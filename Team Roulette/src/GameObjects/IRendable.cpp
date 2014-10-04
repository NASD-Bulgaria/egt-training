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

void IRendable::setX(int x) {
	this->rect.x = x;
}

int IRendable::getY() const {
	return rect.y;
}

void IRendable::draw(SDL_Renderer* gRenderer, double angle, SDL_Point* center,
		SDL_RendererFlip flip) {
	SDL_RenderCopyEx(gRenderer, mTexture, NULL, &rect,angle, center, flip);
	SDL_RenderCopyEx(gRenderer, textTexture , NULL, &textRect, angle, center, flip);
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

void IRendable::setY(int y) {
	this->rect.y = y;
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

void IRendable::setTextRectSize(int x, int y, int w, int h) {
	textRect.x = x;
	textRect.y = y;
	textRect.w = w;
	textRect.h = h;
}

void IRendable::setRenderedText(SDL_Renderer* gRenderer, string text, Uint8 r, Uint8 g, Uint8 b) {
	SDL_Surface * loadedSurface = NULL;
	TTF_Font * font = TTF_OpenFont("Roulette/luximb.ttf", 24);
	if (textTexture != NULL) {
		SDL_DestroyTexture(textTexture);
		textTexture = NULL;
	}
	SDL_Color color = {r,g,b};
	loadedSurface = TTF_RenderText_Solid(font, text.c_str(),color);
	textTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
	TTF_CloseFont(font);
	font = NULL;
	SDL_FreeSurface(loadedSurface);
	loadedSurface = NULL;
}

} /* namespace GameObjects */
