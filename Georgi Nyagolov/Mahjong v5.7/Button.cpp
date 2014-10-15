#include "Button.h"
#include <SDL_image.h>
#include <stdio.h>
#include "Global.h"


Button::Button() :
    Texture()
{
    setPosition(0, 0);
    textureBase = NULL;
    textureMotion = NULL;
    textureDown = NULL;
    textureUp = NULL;
}

Button::~Button()
{
    freeButton();
}

void Button::setPosition(int x, int y)
{
    mPosition.x = x;
    mPosition.y = y;
}

bool Button::handleEvent(SDL_Event e)
{
    bool temp = false;
    //If mouse event happened
    if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN
            || e.type == SDL_MOUSEBUTTONUP)
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);

        //Check if mouse is in button
        bool inside = true;

        //Mouse is left of the button
        if (x < mPosition.x)
        {
            inside = false;
        }
        //Mouse is right of the button
        else if (x > mPosition.x + getWidth())
        {
            inside = false;
        }
        //Mouse above the button
        else if (y < mPosition.y)
        {
            inside = false;
        }
        //Mouse below the button
        else if (y > mPosition.y + getHeight())
        {
            inside = false;
        }

        //Mouse is outside button
        if (!inside)
        {
            Texture::setTexture(textureBase);
        }
        //Mouse is inside button
        else
        {
            //Set mouse over sprite
            switch (e.type)
            {
            case SDL_MOUSEMOTION:
                Texture::setTexture(textureMotion);
                break;

            case SDL_MOUSEBUTTONDOWN:
                Texture::setTexture(textureDown);
                break;

            case SDL_MOUSEBUTTONUP:
                Texture::setTexture(textureUp);
                temp = true;
                if(chunk)
                {
                    Mix_PlayChannel( -1, gLow, 0 );
                }
                break;
            }
        }
    }
    return temp;
}

int Button::getPositionX()
{
    return mPosition.x;
}

int Button::getPositionY()
{
    return mPosition.y;
}

void Button::renderButton()
{
    //Show current button sprite
    SDL_Rect stretchRect;
    stretchRect.x = 0;
    stretchRect.y = 0;
    stretchRect.w = getWidth();
    stretchRect.h = getHeight();
    render(getPositionX(), getPositionY(), &stretchRect);
}

void Button::freeButton()
{
    //Free texture if it exists
    mPosition.x = 0;
    mPosition.y = 0;
    free();
    freeBase();
    freeMotion();
    freeDown();
    freeUp();
}

void Button::freeBase()
{
    if (textureBase != NULL)
    {
        SDL_DestroyTexture(textureBase);
        textureBase = NULL;
    }
}

void Button::freeMotion()
{
    if (textureMotion != NULL)
    {
        SDL_DestroyTexture(textureMotion);
        textureMotion = NULL;
    }
}

void Button::freeDown()
{
    if (textureDown != NULL)
    {
        SDL_DestroyTexture(textureDown);
        textureDown = NULL;
    }
}

void Button::freeUp()
{
    if (textureUp != NULL)
    {
        SDL_DestroyTexture(textureUp);
        textureUp = NULL;
    }
}

bool Button::loadMotionFromFile(std::string path)
{
    //Get rid of preexisting texture
    freeMotion();

    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE,
                        SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        else
        {
            //Get image dimensions
            setWidth(loadedSurface->w);
            setHeight(loadedSurface->h);
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    //Return success
    textureMotion = newTexture;
    return textureMotion != NULL;
}

bool Button::loadDownFromFile(std::string path)
{
    //Get rid of preexisting texture
    freeDown();

    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE,
                        SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        else
        {
            //Get image dimensions
            setWidth(loadedSurface->w);
            setHeight(loadedSurface->h);
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    //Return success
    textureDown = newTexture;
    return textureDown != NULL;
}

bool Button::loadUpFromFile(std::string path)
{
    //Get rid of preexisting texture
    freeUp();

    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE,
                        SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        else
        {
            //Get image dimensions
            setWidth(loadedSurface->w);
            setHeight(loadedSurface->h);
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    //Return success
    textureUp = newTexture;
    return textureUp != NULL;
}

bool Button::loadBaseFromFile(std::string path)
{
    //Get rid of preexisting texture
    freeBase();

    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE,
                        SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        else
        {
            //Get image dimensions
            setWidth(loadedSurface->w);
            setHeight(loadedSurface->h);
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    //Return success
    textureBase = newTexture;
    return textureBase != NULL;
}

SDL_Texture* Button::getTextureBase()
{
    return textureBase;
}

SDL_Texture* Button::getTextureMotion()
{
    return textureMotion;
}

SDL_Texture* Button::getTextureDown()
{
    return textureDown;
}

SDL_Texture* Button::getTextureUp()
{
    return textureUp;
}

