/*
 * BingoEfect.cpp
 *
 *  Created on: 9.10.2014 ã.
 *      Author: sony
 */

#include "BingoEfect.h"
SDL_Renderer* BingoEfect::renderer;
int BingoEfect::cutColor;

BingoEfect::BingoEfect()
{
	renderer = NULL;
	efectTexture = NULL;
	degrees = 0;
	process = 0;
	cuttingColor.reverse = 0;
	cutColor = 0;
	cuttingColor.g = 0;
	cuttingColor.b = 0;
	cuttingColor.reverse = 0;
}

void BingoEfect::loadBingoEfects(string path)
{
	SDL_Surface* tempSurface = IMG_Load(path.c_str());

		if(tempSurface == NULL)
		{
			printf("Temporary button surface failed to load.");
		}
		else
		{
			//Color key image
			SDL_SetColorKey( tempSurface, SDL_TRUE, SDL_MapRGB( tempSurface->format, 0xFF, 0x00, 0x00 ) );

			efectTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);

			if(efectTexture == NULL)
			{
				printf("Button texture failed to load.");
			}
			else
			{
				m_Rect.w = 75;
//						tempSurface->w-25;
				m_Rect.h =75;
//						tempSurface->h-25;
			}
			SDL_FreeSurface( tempSurface );
		}
}

void BingoEfect::fillEfects(string efectPath, int x, int y, vector<BingoEfect>& efectContainer, BingoEfect temp)
{
	temp.loadBingoEfects(efectPath.c_str());
	temp.setEfectRect(x, y);

	efectContainer.push_back(temp);
}

void BingoEfect::fillEfectsInVector(vector<BingoEfect>& efectContainer, BingoEfect obj)
{
	fillEfects("LaFinEffect/1.png", 335, 0,efectContainer, obj);
	fillEfects("LaFinEffect/2.png", 410, 24,efectContainer, obj);
	fillEfects("LaFinEffect/3.png", 485, 0,efectContainer, obj);
	fillEfects("LaFinEffect/4.png", 560, 24,efectContainer, obj);
	fillEfects("LaFinEffect/5.png", 635, 0,efectContainer, obj);
}

void BingoEfect::makeEffect(int x, int degrees)
{
	colorEffect(0);
	m_Rect.x = x;
	SDL_RenderCopyEx(renderer, efectTexture,NULL, &m_Rect, degrees, NULL, SDL_FLIP_NONE );
}

void BingoEfect::setEfectRect(int x, int y)
{
	m_Rect.x = x;
	m_Rect.y = y;
}

void BingoEfect::setEfectRectWH(int w, int h)
{
	m_Rect.w = w;
	m_Rect.h = h;
}

void BingoEfect::setRenderer(SDL_Renderer* rend)
{
	renderer = rend;
}

void BingoEfect::moveLaFinEffect(int x, int direction)
{
	switch(process)
	{
		case 0:
			if(shrink())
			{
				process++;
			}
			break;
		case 1:
			if(moveDown())
			{
				process++;
			}
			break;
		case 2:
			if (chooseDirection(x, direction))
			{
				process++;
			}
			break;
		case 3:
			if (moveWhileSpining(direction))
			{
				process++;
			}
			break;
		case 4:
			colorEffect(10);
			break;
		default: break;
	}

	SDL_RenderCopyEx(renderer, efectTexture,NULL, &m_Rect, degrees, NULL, SDL_FLIP_NONE );
}

bool BingoEfect::shrink()
{
	m_Rect.w --;
	m_Rect.h --;

	return m_Rect.w == 40;
}

bool BingoEfect::moveDown()
{
		m_Rect.y +=2;

	return m_Rect.y == 100;
}

bool BingoEfect::chooseDirection(int x, int direction)
{
		m_Rect.x = m_Rect.x + (2*direction);
		degrees = degrees + (11*direction);

	return m_Rect.x == x;
}

bool BingoEfect::moveWhileSpining(int direction)
{
			degrees = degrees + (4 * direction);

		if (degrees >= 360 || degrees <= -360)
		{
			degrees = 0;
		}
		return degrees == 0;
}

void BingoEfect::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
    //Modulate texture
    SDL_SetTextureColorMod( efectTexture, red, green, blue );
}

void BingoEfect::colorEffect(int speed)
{
	if (cuttingColor.reverse == 0)
	{
		if (cutColor >= 120)
		{
			cuttingColor.reverse = 1;
		}
		cutColor += speed;
	}
	else
	{
		if (cutColor <= 5)
		{
			cuttingColor.reverse = 0;
		}
		cutColor -= speed;
	}

	setColor(100 + cutColor, 100 + cutColor, 100 + cutColor);
}

void BingoEfect::returnDefaultValuesEffect(int y)
{
	m_Rect.w = 75;
	m_Rect.h = 75;
	m_Rect.y = y;
	process = 0;
}

BingoEfect::~BingoEfect()
{
	// TODO Auto-generated destructor stub
}
