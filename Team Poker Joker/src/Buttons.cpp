/*
 * Buttons.cpp
 *
 *  Created on: Sep 30, 2014
 *      Author: vasko
 */

#include "Buttons.h"

Buttons::Buttons()
{
	x = 0;
	y = 0;
	w = 0;
	h = 0;
}

Buttons::Buttons(int x, int y, int w, int h)
{
	setX(x);
	setY(y);
	setW(w);
	setH(h);
}

Buttons::~Buttons()
{

}

int Buttons::getH()
{
	return h;
}

void Buttons::setH(int h)
{
	this->h = h;
}

int Buttons::getW()
{
	return w;
}

void Buttons::setW(int w)
{
	this->w = w;
}

int Buttons::getX()
{
	return x;
}

void Buttons::setX(int x)
{
	this->x = x;
}

int Buttons::getY()
{
	return y;
}

void Buttons::setY(int y)
{
	this->y = y;
}

bool Buttons::checkButton(int mouseX, int mouseY)
{
	return (mouseX > getX() && mouseX < getX() + getW() && mouseY > getY()
			&& mouseY < getY() + getH());
}
