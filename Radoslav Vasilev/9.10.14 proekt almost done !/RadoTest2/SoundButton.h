#ifndef SOUNDBUTTON_H
#define SOUNDBUTTON_H
#include "WidgetButtonBase.h"


class Mix_Chunk;
class SoundButton :public WidgetButtonBase
{
public:
    SoundButton(SDL_Texture* default_image, SDL_Texture* mouse_over_image, SDL_Texture* clicked_image, SDL_Rect destination, Mix_Chunk *sound_effect_select);

    void MouseOverBecome();
    void MouseOverEnds();
    void ButtonPressed(Uint32 mouse_button_state);
    void ButtonReleased(Uint32 mouse_button_state);
private:
    bool sound_on;
    Mix_Chunk* sound_effect_select;
};

#endif // SOUNDBUTTON_H
