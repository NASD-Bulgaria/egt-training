/*
 * Button.h
 *
 *  Created on: Sep 28, 2014
 *      Author: Safet
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Button
{
public:
	Button();
	virtual ~Button();
	void fillInVector(vector<Button>&, Button);
	bool findButton(SDL_Event&, int, int);
	void render();

	void setRenderer(SDL_Renderer*);
private:
	bool loadButtonImage(string);
	void setButtonRect(int, int);
	void setPath(string);
	void fill(string, int, int, vector<Button>&, Button);

	static SDL_Renderer* renderer;
	SDL_Texture* buttonTexture;
	SDL_Rect m_Rect;
	string path;
};

#endif /* BUTTON_H_ */
