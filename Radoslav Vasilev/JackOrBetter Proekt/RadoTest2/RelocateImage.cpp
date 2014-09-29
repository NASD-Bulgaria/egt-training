

RelocateImage::RelocateImage(SDL_Texture *image,SDL_Rect destination)
    :WidgetButtonBase(image,NULL,NULL,destination),
      pressed(false)
{
}

RelocateImage::~RelocateImage()
{
}

void RelocateImage::Draw(SDL_Renderer *renderer)
{
    if(!pressed)
    {
        WidgetButtonBase::Draw(renderer);
    }
}

bool RelocateImage::HandleMouseEvent(Uint32 mouse_button_state, int x, int y)
{
    if( !pressed && PointInRect(GetLocation(),x,y))
    {
        if(mouse_button_state)
        {
            pressed = !pressed;
            return true;
        }
    }

    if(pressed)
    {
        if(mouse_button_state)
        {
        SDL_Rect old_destination = GetLocation();
        old_destination.x = x;
        old_destination.y = y;
        SetLocation(old_destination);
        ButtonReleased(mouse_button_state);
        pressed = !pressed;

        return true;
        }
    }

    return false;
}

void RelocateImage::MouseOverBecome()
{
}

void RelocateImage::MouseOverEnds()
{
}

void RelocateImage::ButtonPressed(Uint32)
{
}

void RelocateImage::ButtonReleased(Uint32)
{
}
