#ifndef HELPBUTTON_H
#define HELPBUTTON_H
#include "WidgetButtonBase.h"

class Mix_Chunk;
class Application;
class HelpButton :public WidgetButtonBase
{
public:
    HelpButton(SDL_Texture*, SDL_Texture*, SDL_Rect, Application*, Mix_Chunk*);

    void ButtonPressed(Uint32);
    void ButtonReleased(Uint32);
private:
    Application* app;
    Mix_Chunk* sound_effect;
};

#endif // HELPBUTTON_H
