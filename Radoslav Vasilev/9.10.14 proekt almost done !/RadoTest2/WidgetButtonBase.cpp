#include "WidgetButtonBase.h"
#include "RenderableImage.h"
#include <SDL2/SDL.h>
#include <iostream>

WidgetButtonBase::WidgetButtonBase(SDL_Texture* default_image, SDL_Texture* mouse_over_image, SDL_Texture* clicked_image, SDL_Rect destination):
    current_image(default_image),
    default_image(default_image),
    mouse_over_image(mouse_over_image),
    clicked_image(clicked_image),
    destination(destination),
    current_button_state ( StateNone ),
    old_button_state ( 0 )
{
}

WidgetButtonBase::~WidgetButtonBase()
{
}

void WidgetButtonBase::Draw(SDL_Renderer *renderer)
{
     SDL_RenderCopyEx ( renderer,current_image,NULL,&destination,0,NULL,SDL_FLIP_NONE );
}

bool WidgetButtonBase::HandleMouseEvent(Uint32 mouse_button_state, int x, int y)
{

    if(PointInRect(destination,x,y))
    {

        HandleInButtonEvents ( mouse_button_state );
        return true;
    }

    HandleOutButtonEvents();

    return false;
}

void WidgetButtonBase::MouseOverBecome()
{
}

void WidgetButtonBase::MouseOverEnds()
{
}

void WidgetButtonBase::ButtonPressed(Uint32 )
{
}

void WidgetButtonBase::ButtonReleased(Uint32 )
{

        if( current_image == clicked_image)
        {
            current_image=default_image;
        }
        else
        {
           current_image =  clicked_image;
        }
}

bool WidgetButtonBase::PointInRect(const SDL_Rect &r, int x, int y)
{
    if((x>=r.x)&&(x<(r.x+r.w))&&(y>=r.y)&&(y<(r.y+r.h)))
    {
        return true;
    }

    return false;
}

void WidgetButtonBase::HandleInButtonEvents(Uint32 mouse_button_state)
{
    switch ( current_button_state )
    {
    case StateNone:
        current_button_state = StateMouseOver;
        MouseOverBecome();
        break;

    case StateMouseOver:
        if ( mouse_button_state && mouse_button_state != old_button_state )
        {
            current_button_state = StateMousePressed;
            ButtonPressed ( mouse_button_state );
        }
        break;

    case StateMousePressed:
        if ( !mouse_button_state )
        {
            current_button_state = StateMouseOver;
            ButtonReleased ( mouse_button_state );      
        }
        break;
    }

    old_button_state = mouse_button_state;
}

void WidgetButtonBase::HandleOutButtonEvents()
{
    if ( current_button_state != StateNone )
    {
        current_button_state = StateNone;
        MouseOverEnds();
    }
}

void WidgetButtonBase::SetLocation(SDL_Rect destination)
{
    this->destination = destination;
}

const SDL_Rect &WidgetButtonBase::GetLocation() const
{
    return destination;
}
SDL_Rect* WidgetButtonBase::getDestination()
{
    return &destination;
}

void WidgetButtonBase::setDestination(const SDL_Rect &value)
{
    destination = value;
}


void WidgetButtonBase::setDefault_image(SDL_Texture *value)
{
    if(default_image==current_image)
    {
       default_image = value;
       current_image = value;
       return;
    }
    default_image = value;
}

void WidgetButtonBase::setMouse_over_image(SDL_Texture *value)
{
    if(mouse_over_image==current_image)
    {
       mouse_over_image = value;
       current_image = value;
       return;
    }
    mouse_over_image = value;
}

void WidgetButtonBase::setClicked_image(SDL_Texture *value)
{
    if(clicked_image==current_image)
    {
       clicked_image = value;
       current_image = value;
       return;
    }
    clicked_image = value;
}





