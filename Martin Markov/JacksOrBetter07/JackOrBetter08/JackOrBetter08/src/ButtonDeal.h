#ifndef BUTTONDEAL_H
#define BUTTONDEAL_H
#include "WidgetButtonBase.h"

class Mix_Chunk;
class Application;
class ButtonDeal :public WidgetButtonBase
{
public:
    ButtonDeal(SDL_Texture* default_image,SDL_Texture* mouse_over_image,SDL_Texture* clicked_image,SDL_Rect destination,Application *app,Mix_Chunk* sound);
    void ButtonReleased(Uint32 mouse_button_state);
    void SetButtonState(bool button_state);
    void ButtonPressed(Uint32 mouse_button_state);

private:
    Application* app;
    Mix_Chunk* sound;

};

#endif // BUTTONDEAL_H
