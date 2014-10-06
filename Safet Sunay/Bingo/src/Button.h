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

#include <stdio.h>
#include <vector>
#include <string>


using namespace std;

class Button
{
public:
	Button();
	virtual ~Button();
	void vectorFill(vector<Button*>&);
	bool findButton(SDL_Event &);
	void render();
private:
	bool loadButtonImage(string);
	void setButtonRect(int, int);
	void setPath(string);
	void fill(string, int, int, vector<Button*>&);

	SDL_Renderer* renderer;
	SDL_Texture* buttonTexture;
	SDL_Rect tempRect;
	Button* temp;
	string path;
};

#endif /* BUTTON_H_ */
