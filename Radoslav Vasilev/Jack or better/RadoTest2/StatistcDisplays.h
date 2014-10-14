#ifndef STATISTCDISPLAYS_H
#define STATISTCDISPLAYS_H
#include "IWidget.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
class SDL_Texture;


class StatistcDisplays : public IWidget
{
public:
    StatistcDisplays( SDL_Rect);
    virtual ~ StatistcDisplays();
   void UpdateText(int, TTF_Font*, SDL_Renderer*);
   void Draw(SDL_Renderer*);
   bool HandleMouseEvent(Uint32, int, int);
private:
   SDL_Texture* text;
   SDL_Rect destination_text;
};

#endif // STATISTCDISPLAYS_H
