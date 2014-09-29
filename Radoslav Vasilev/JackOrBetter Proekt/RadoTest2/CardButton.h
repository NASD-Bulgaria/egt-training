#ifndef CARDBUTTON_H
#define CARDBUTTON_H
#include "WidgetButtonBase.h"


class Application;

class CardButton: public WidgetButtonBase
{
public:
    CardButton(SDL_Texture* card_image, SDL_Texture* held_image, SDL_Rect destination,Application* app);
    void MouseOverBecome();
    void MouseOverEnds();
    void ButtonPressed(Uint32 mouse_button_state);
    void ButtonReleased(Uint32 mouse_button_state);
    void Draw(SDL_Renderer* renderer);
    bool GetHeld() const;
    void SetImage(SDL_Texture* image);
    void SetHeld(bool value);
    void HeldReset();
private:
    Application* app;
    SDL_Texture* held_image;
    bool held;
    SDL_Rect held_destination;
    void RecalculateHeldDestination();
};

#endif // CARDBUTTON_H
