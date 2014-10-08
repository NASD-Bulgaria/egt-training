#ifndef CARDBUTTON_H
#define CARDBUTTON_H
#include "WidgetButtonBase.h"

class Mix_Chunk;
class Application;

class CardButton: public WidgetButtonBase
{
public:
    CardButton(SDL_Texture* card_image, SDL_Texture* held_image, SDL_Rect destination, Application* app, Mix_Chunk *sound);
    void MouseOverBecome();
    void MouseOverEnds();
    void ButtonPressed(Uint32 mouse_button_state);
    void ButtonReleased(Uint32 mouse_button_state);
    void Draw(SDL_Renderer* renderer);
    bool GetHeld() const;
    void SetImage(SDL_Texture* image);
    void SetHeld(bool value);
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
