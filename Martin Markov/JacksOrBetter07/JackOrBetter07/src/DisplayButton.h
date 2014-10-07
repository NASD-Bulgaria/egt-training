#ifndef DISPLAYBUTTON_H
#define DISPLAYBUTTON_H
#include "IWidget.h"
#include <SDL2/SDL.h>
class SDL_Texture;


class DisplayButton :public IWidget
{
private:

    SDL_Texture* image_display;
    SDL_Texture* image_background; 
    SDL_Rect destination;
    SDL_Rect destination_text;
    SDL_Rect destination_profit; //da se mahne
    int check; // da se mahne
    int score;
public:
    DisplayButton(SDL_Texture* image_display, SDL_Texture* image_background, SDL_Rect destination, int check);
    void Draw(SDL_Renderer* renderer);
    bool HandleMouseEvent(Uint32 mouse_button_state,int x,int y);
    int getCheck() const;               // da se mahne
    void setCheck(int value);          // da se mahne
    void SetCurrentScore(int value); // da se mahne
    void CalculateDestinations();   // da se mahne
};

#endif // DISPLAYBUTTON_H
