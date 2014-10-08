#ifndef BACKGROUND_H
#define BACKGROUND_H

class SDL_Renderer;

class SDL_Texture;

class Background
{
public:
    Background();
    ~Background();
    void Draw(SDL_Renderer* renderer);
    void SetImage(SDL_Texture* image);
private:
    SDL_Texture* image;

};

#endif // BACKGROUND_H
