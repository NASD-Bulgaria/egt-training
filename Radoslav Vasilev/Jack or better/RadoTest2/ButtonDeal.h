#ifndef BUTTONDEAL_H
#define BUTTONDEAL_H
#include "WidgetButtonBase.h"

class Mix_Chunk;
class Application;
class ButtonDeal :public WidgetButtonBase
{
public:
    ButtonDeal(SDL_Texture*, SDL_Texture*, SDL_Rect, Application*, Mix_Chunk*);
    void ButtonReleased(Uint32);
    void SetButtonState(bool);
    void ButtonPressed(Uint32);

private:
    Application* app;
    Mix_Chunk* sound;

};

#endif // BUTTONDEAL_H
