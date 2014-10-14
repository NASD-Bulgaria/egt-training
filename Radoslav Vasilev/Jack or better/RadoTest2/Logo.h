/*
 * Logo.h
 *
 *  Created on: Oct 11, 2014
 *      Author: Keen
 */

#ifndef LOGO_H_
#define LOGO_H_

#include "IWidget.h"
#include <SDL2/SDL.h>
class SDL_Texture;

class Logo : public IWidget
{
private:
    SDL_Texture* image_display;
    SDL_Rect destination;
public:
	Logo(SDL_Texture*, SDL_Rect);
	void Draw(SDL_Renderer*);
	bool HandleMouseEvent(Uint32, int, int);
	void SetImage(SDL_Texture*);
	virtual ~Logo();
};

#endif /* LOGO_H_ */
