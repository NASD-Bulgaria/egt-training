/*
 * IRendable.h
 *
 *  Created on: Sep 29, 2014
 *      Author: NandM
 */

#ifndef IRENDABLE_H_
#define IRENDABLE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;
namespace GameObjects {

class IRendable {
public:
	IRendable(int x = 0, int y = 0, int width = 0, int height = 0);
	virtual bool loadFromFile(SDL_Renderer* gRenderer, std::string path);
	virtual ~IRendable();
	virtual void draw(SDL_Renderer*);
	virtual bool isClicked(int x, int y);
	int getHeight() const;
	void setHeight(int height);
	int getWidth() const;
	void setWidth(int width);
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);

protected:
	SDL_Texture * mTexture;
	SDL_Rect rect;

};

} /* namespace GameObjects */

#endif /* IRENDABLE_H_ */
