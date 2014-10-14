#ifndef SOUNDBUTTON_H
#define SOUNDBUTTON_H
#include "WidgetButtonBase.h"


class Mix_Chunk;
class SoundButton :public WidgetButtonBase
{
public:
    SoundButton(SDL_Texture*, SDL_Texture*, SDL_Rect, Mix_Chunk*);

    void ButtonPressed(Uint32);
    void ButtonReleased(Uint32);
private:
    bool sound_on;
    Mix_Chunk* sound_effect_select;
};

#endif // SOUNDBUTTON_H
