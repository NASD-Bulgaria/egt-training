#ifndef LBUTTON_H
#define LBUTTON_H

#include "LTexture.h"

class LButton : public LTexture
{
public:
    LButton();
    virtual ~LButton();
    //Sets top left position
    void setPosition( int x, int y );

    //Handles mouse event
    bool handleEvent( SDL_Event e );

    int getPositionX();
    int getPositionY();

    void renderButton();
    //Deallocates tile
    void freeButton();
    bool loadMotionFromFile( std::string path );
    bool loadDownFromFile( std::string path );
    bool loadUpFromFile( std::string path );
    bool loadBaseFromFile( std::string path );

    SDL_Texture* getTextureBase();
    SDL_Texture* getTextureMotion();
    SDL_Texture* getTextureDown();
    SDL_Texture* getTextureUp();

protected:
private:
    void freeBase();
    void freeMotion();
    void freeDown();
    void freeUp();

    //Top left position
    SDL_Point mPosition;

    SDL_Texture* textureBase;
    SDL_Texture* textureMotion;
    SDL_Texture* textureDown;
    SDL_Texture* textureUp;
};

#endif // LBUTTON_H
