#ifndef BUTTON_H_
#define BUTTON_H_

#include <SDL.h>
#include <SDL2/SDL_image.h>

struct Color {
	Uint8 red, green, blue, alpha;
};

class Button
{
public:

	const static int WIDTH = 43;
	const static int HEIGHT = 24;

	Button(int number = 0, int x = 0, int y = 0);

	void setColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);
	void setInitialColor();
	void draw(SDL_Renderer*);

	virtual ~Button();
	void setPosition(int x, int y);
	const int getNumber() const;
	bool Clicked;
	void setNumber(int number);

private:
	Color currentColor;
	const static Color InitialColor;
	SDL_Rect rect;
	SDL_Rect outline;
	int number;

};

#endif
