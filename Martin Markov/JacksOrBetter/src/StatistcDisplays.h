#ifndef STATISTCDISPLAYS_H
#define STATISTCDISPLAYS_H
#include "IWidget.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
class SDL_Texture;


class StatistcDisplays :public IWidget
{
public:
    StatistcDisplays( SDL_Rect destination_text);
    ~ StatistcDisplays();
   void UpdateText(int value, TTF_Font* font, SDL_Renderer *renderer);
   void Draw(SDL_Renderer* renderer);
   bool HandleMouseEvent(Uint32 mouse_button_state,int x,int y);
private:
  // SDL_Texture* background;
   SDL_Texture* text;
 //  SDL_Rect destination_bg;
   SDL_Rect destination_text;

};

#endif // STATISTCDISPLAYS_H
