/*
 * Button.cpp
 *
 *  Created on: Sep 28, 2014
 *      Author: Safet
 */

#include "Button.h"

SDL_Renderer* Button::renderer;

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
		printf("Temporary button surface failed to load.");
		return false;
	}
	else
	{
		//Color key image
		SDL_SetColorKey( tempSurface, SDL_TRUE, SDL_MapRGB( tempSurface->format, 0xFF, 0x00, 0x00 ) );

		buttonTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);

		if(buttonTexture == NULL)
		{
			printf("Button texture failed to load.");
			return false;
		}
		else
		{
			m_Rect.w = tempSurface->w;
			m_Rect.h = tempSurface->h;
		}
		SDL_FreeSurface( tempSurface );
	}

	return true;
}

void Button::setButtonRect(int x, int y)
{
	m_Rect.x = x;
	m_Rect.y = y;
}

void Button::fill(string imagePath, int x, int y, vector<Button>& buttonContainer, Button temp)
{
	temp.loadButtonImage(imagePath.c_str());
	temp.setButtonRect(x, y);

	buttonContainer.push_back(temp);
}

void Button::fillInVector(vector<Button>& buttonContainer, Button temp)
{
	fill("Images/NewGame.png", 851, 150, buttonContainer, temp);
	fill("Images/Rules.png", 851, 310, buttonContainer, temp);
	fill("Images/Info.png", 851, 230, buttonContainer, temp);
	fill("Images/Quit.png", 851, 390, buttonContainer, temp);
	fill("Images/PLAY.png", 400, 451, buttonContainer, temp);
	fill("Images/MusicButtonMouseOver.png", 874, 52, buttonContainer, temp);
	fill("Images/SoundButtonMouseOver.png", 926, 48, buttonContainer, temp);
}

void Button::render()
{
	SDL_RenderCopy(renderer, buttonTexture, NULL, &m_Rect);
}

bool Button::findButton(SDL_Event& event, int x, int y)
{
	SDL_GetMouseState(&x, &y);

	if (event.type == SDL_MOUSEMOTION)
	{
		int buttonWidth = m_Rect.x + m_Rect.w;
		int buttonHeight = m_Rect.y + m_Rect.h;

		if(x >= m_Rect.x && x <= buttonWidth
		&& y >= m_Rect.y && y <= buttonHeight)
		{
			return true;
		}
	}

	return false;
}

void Button::setRenderer(SDL_Renderer* rend)
{
	renderer = rend;
}

Button::~Button()
{
}
