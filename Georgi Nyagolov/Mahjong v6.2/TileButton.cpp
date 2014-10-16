#include "TileButton.h"

TileButton::TileButton(faceType face) {
	blocked = true;
	this->face = face;
}

TileButton::~TileButton() {
	freeTile();
}

bool TileButton::getBlocked() {
	return blocked;
}
void TileButton::setBlocked(bool checking) {
	blocked = checking;
}

faceType TileButton::getFace() const {
	return face;
}

void TileButton::setFace(faceType face) {
	this->face = face;
}

void TileButton::freeTile() {
	freeButton();
	this->face = NONE;
}

bool TileButton::handleEvent(SDL_Event e, int &coordI, int &coordJ) {
	bool temp = false;
	//If mouse event happened
	if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN
			|| e.type == SDL_MOUSEBUTTONUP) {
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);

		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if (x < getPositionX()) {
			inside = false;
		}
		//Mouse is right of the button
		else if (x > getPositionX() + getWidth()) {
			inside = false;
		}
		//Mouse above the button
		else if (y < getPositionY()) {
			inside = false;
		}
		//Mouse below the button
		else if (y > getPositionY() + getHeight()) {
			inside = false;
		}

		//Mouse is outside button
		if (!inside) {
			Texture::setTexture(getTextureBase());
		}
		//Mouse is inside button
		else {
			//Set mouse over sprite
			switch (e.type) {
			case SDL_MOUSEMOTION:
				if (getBlocked()) {
					Texture::setTexture(getTextureMotion());
				}
				break;

			case SDL_MOUSEBUTTONDOWN:
				if (getBlocked()) {
					Texture::setTexture(getTextureDown());
				}
				break;

			case SDL_MOUSEBUTTONUP:
				if (getBlocked()) {
					Texture::setTexture(getTextureUp());
					coordI = coordinates.i;
					coordJ = coordinates.j;
					temp = true;
				}
				break;
			}
		}
	}
	return temp;
}

