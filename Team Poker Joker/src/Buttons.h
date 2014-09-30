/*
 * Buttons.h
 *
 *  Created on: Sep 30, 2014
 *      Author: vasko
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_
#include "SDL.h"
#include "SDL_image.h"
#include "Texture.h"
class Buttons
{
public:
	Buttons();
	Buttons(int x, int y, int w, int h);
	virtual ~Buttons();

	bool checkButton(int mouseX, int mouseY);

	int getH();
	void setH(int h);
	int getW();
	void setW(int w);
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);

private:

	int x;
	int y;
	int w;
	int h;
};

#endif /* BUTTONS_H_ */
