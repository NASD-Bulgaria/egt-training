#ifndef CARDBUTTON_H
#define CARDBUTTON_H
#include "WidgetButtonBase.h"

class Mix_Chunk;
class Application;

class CardButton: public WidgetButtonBase
{
public:
    CardButton(SDL_Texture*, SDL_Texture*, SDL_Rect, Application*, Mix_Chunk*);

    void ButtonPressed(Uint32);
    void ButtonReleased(Uint32);
    void Draw(SDL_Renderer*);
    bool GetHeld() const;
    void SetImage(SDL_Texture*);
    void SetHeld(bool);
    void HeldReset();
    void AutoHeldSet();
private:
    Application* app;
    SDL_Texture* held_image;
    bool held;
    Mix_Chunk* sound;
    SDL_Rect held_destination;
    void RecalculateHeldDestination();
};

#endif // CARDBUTTON_H
