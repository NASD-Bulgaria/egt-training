#ifndef IRENDERABLEBASE_H
#define IRENDERABLEBASE_H

class SDL_Renderer;

class IRenderable
{
public:
    virtual void Draw(SDL_Renderer* renderer) = 0;
    virtual ~IRenderable(){}
};

#endif // IRENDERABLEBASE_H
