#ifndef LTEXTURE_H
#define LTEXTURE_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class Texture
{
public:
    //Initializes variables
    Texture();

    //Deallocates memory
    virtual ~Texture();

    //Loads image at specified path
    bool loadFromFile( std::string path );

#ifdef _SDL_TTF_H
    //Creates image from font string
    bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
#endif

    //Deallocates texture
    void free();

    //Renders texture at given point
    void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

    //Gets image dimensions
    int getWidth();
    int getHeight();
    SDL_Texture* getTexture();

    void setWidth(int w);
    void setHeight(int h);
    void setTexture(SDL_Texture* texture);


protected:
    //The actual hardware texture
    SDL_Texture* mTexture;

    //Image dimensions
    int mWidth;
    int mHeight;
};


#endif // LTEXTURE_H
