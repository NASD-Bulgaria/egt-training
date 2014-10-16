#include "Animation.h"
#include <sstream>
#include <SDL_image.h>
#include <stdio.h>

Animation::Animation() :
		start(false), startTicks(SDL_GetTicks()) {
	setPosition(0, 0);
	for (int i = 0; i < NUMBER_ANIMATION; ++i) {
		animations[i] = NULL;
	}
}

Animation::~Animation() {
	freeAnimation();
}

void Animation::freeAnimation() {
	free();
	for (int i = 0; i < NUMBER_ANIMATION; ++i) {
		if (animations[i] != NULL) {
			SDL_DestroyTexture(animations[i]);
			animations[i] = NULL;
		}
	}
}

bool Animation::loadAnimationFromFile(SDL_Renderer* renderer, std::string path) {
	bool temp = true;
	freeAnimation();

	for (int i = 0; i < NUMBER_ANIMATION; ++i) {
		SDL_Texture* newTexture = NULL;

		std::stringstream tempPath;
		tempPath.str("");
		tempPath << path << i << ".png";

		SDL_Surface* loadedSurface = IMG_Load(tempPath.str().c_str());
		if (loadedSurface == NULL) {
			printf("Unable to load image %s! SDL_image Error: %s\n",
					tempPath.str().c_str(), IMG_GetError());
		} else {
			//Color key image
			SDL_SetColorKey(loadedSurface, SDL_TRUE,
					SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

			//Create texture from surface pixels
			newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
			if (newTexture == NULL) {
				printf("Unable to create texture from %s! SDL Error: %s\n",
						tempPath.str().c_str(), SDL_GetError());
			} else {
				//Get image dimensions
				mWidth = loadedSurface->w;
				mHeight = loadedSurface->h;
			}

			//Get rid of old loaded surface
			SDL_FreeSurface(loadedSurface);
		}
		animations[i] = newTexture;
		temp = (animations[i] != NULL);
		if (!temp) {
			return temp;
		}
	}
	std::stringstream tempPath;
	tempPath.str("");
	tempPath << path << "0.png";
	temp = loadFromFile(renderer, tempPath.str());
	return temp;
}

void Animation::setPosition(int x, int y) {
	position.x = x;
	position.y = y;
}

void Animation::setToDefault() {
	start = false;
	setPosition(0, 0);
}

void Animation::startAnimation(int x, int y) {
	start = true;
	startTicks = SDL_GetTicks();
	setPosition(x, y);
}

void Animation::renderAnimation(SDL_Renderer* renderer) {
	if (start) {
		calculateAnimation();
		render(renderer, position.x, position.y);
	}
}

void Animation::calculateAnimation() {
	if ((SDL_GetTicks() - startTicks) < 1000) {
		Texture::setTexture(animations[(SDL_GetTicks() - startTicks) / 100]);
	} else {
		Texture::setTexture(animations[0]);
		setToDefault();
	}
}

