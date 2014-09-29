#include "Button.h"

Button::Button(int number, int x, int y) {
	this->number = number;
	setInitialColor();
	setPosition(x, y);
	rect.w = WIDTH;
	rect.h = HEIGHT;
	outline.w = WIDTH;
	outline.h = HEIGHT;
	Clicked = false;

}

void Button::draw(SDL_Renderer* gRenderer)
{
	SDL_SetRenderDrawColor(gRenderer, currentColor.red, currentColor.green,
			currentColor.blue, currentColor.alpha);
	SDL_RenderFillRect(gRenderer, &rect);
	SDL_SetRenderDrawColor(gRenderer, 0, 0,
			0, InitialColor.alpha);
	SDL_RenderDrawRect(gRenderer, &outline);
}

Button::~Button() {
}

const int Button::getNumber() const
{
	return number;
}

void Button::setColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
	this->currentColor.red = red;
	this->currentColor.green = green;
	this->currentColor.blue = blue;
	this->currentColor.alpha = alpha;
}

void Button::setPosition(int x, int y)
{
	this->rect.x = x;
	this->rect.y = y;
	this->outline.x = x;
	this->outline.y = y;
}

void Button::setInitialColor() {
	this->currentColor.red = InitialColor.red;
	this->currentColor.green = InitialColor.green;
	this->currentColor.blue = InitialColor.blue;
	this->currentColor.alpha = InitialColor.alpha;
}

void Button::setNumber(int number) {
	this->number = number;
}

const Color Button::InitialColor = { 102, 147, 203, 128 };
