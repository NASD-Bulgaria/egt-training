#ifndef DISPLAYBUTTON_H
#define DISPLAYBUTTON_H
#include "IWidget.h"
#include <SDL2/SDL.h>
class SDL_Texture;


class WinDisplay :public IWidget
{
private:

    SDL_Texture* image_display;
    SDL_Rect destination;
    SDL_Rect destination_text;
    int score;
public:
    WinDisplay(SDL_Texture* image_display, SDL_Rect destination);
    void Draw(SDL_Renderer* renderer);
    bool HandleMouseEvent(Uint32 mouse_button_state,int x,int y);
    void SetCurrentScore(int value);

    virtual ~WinDisplay();
};

#endif // DISPLAYBUTTON_H
