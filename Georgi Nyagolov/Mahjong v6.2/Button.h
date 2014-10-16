#ifndef LBUTTON_H
#define LBUTTON_H

#include "Texture.h"

class Button: public Texture {
public:
	Button();
	virtual ~Button();
	//Sets top left position
	void setPosition(int x, int y);

	//Handles mouse event
	bool handleEvent(SDL_Event e);

	int getPositionX();
	int getPositionY();

	void renderButton(SDL_Renderer* renderer);
	//Deallocates tile
	void freeButton();
	bool loadMotionFromFile(SDL_Renderer* renderer, std::string path);
	bool loadDownFromFile(SDL_Renderer* renderer, std::string path);
	bool loadUpFromFile(SDL_Renderer* renderer, std::string path);
	bool loadBaseFromFile(SDL_Renderer* renderer, std::string path);

	SDL_Texture* getTextureBase();
	SDL_Texture* getTextureMotion();
	SDL_Texture* getTextureDown();
	SDL_Texture* getTextureUp();

protected:
private:
	void freeBase();
	void freeMotion();
	void freeDown();
	void freeUp();

	//Top left position
	SDL_Point mPosition;

	SDL_Texture* textureBase;
	SDL_Texture* textureMotion;
	SDL_Texture* textureDown;
	SDL_Texture* textureUp;
};

#endif // LBUTTON_H
