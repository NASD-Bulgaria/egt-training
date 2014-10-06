/*
 * Button.cpp
 *
 *  Created on: Sep 28, 2014
 *      Author: Safet
 */

#include "Button.h"

Button::Button()
{
	renderer = NULL;
	buttonTexture = NULL;
}

bool Button::loadButtonImage(string path)
{
	SDL_Surface* tempSurface = IMG_Load(path.c_str());

	if(tempSurface == NULL)
	{
		printf("Temp button surface failed to load.");
		return false;
	}
	else
	{
		buttonTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
		if(buttonTexture == NULL)
		{
			printf("Button texture failed to load.");
			return false;
		}
		else
		{
			tempRect.w = tempSurface->w;
			tempRect.h = tempSurface->h;
		}

	}

	return true;
}

void Button::setButtonRect(int x, int y)
{
	tempRect.x = x;
	tempRect.y = y;
}

void Button::fill(string imagePath, int x, int y, vector<Button*>& buttonContainer)
{
	temp = new Button;
	temp->loadButtonImage(imagePath.c_str());
	temp->setButtonRect(x, y);

	buttonContainer.push_back(temp);
}

void Button::vectorFill(vector<Button*>& buttonContainer)
{
	fill("NewGame.png", 851, 150, buttonContainer);
	fill("Rules.png", 851, 310, buttonContainer);
	fill("Info.png", 851, 230, buttonContainer);
	fill("Quit.png", 851, 390, buttonContainer);
	fill("PLAY.png", 400, 451, buttonContainer);
	fill("MusicButtonMouseOver.png", 874, 52, buttonContainer);
	fill("SoundButtonMouseOver.png", 926, 48, buttonContainer);
}

void Button::render()
{
	SDL_RenderCopy(renderer, buttonTexture, NULL, &tempRect);
}

bool Button::findButton(SDL_Event &event)
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	if (event.type == SDL_MOUSEMOTION || SDL_MOUSEBUTTONDOWN)
	{
		int buttonWidth = tempRect.x + tempRect.w;
		int buttonHeight = tempRect.y + tempRect.h;

		if(x >= tempRect.x && x <= buttonWidth
		&& y >= tempRect.y && y <= buttonHeight)
		{
			return true;
		}
	}

	return false;
}

Button::~Button()
{
}
