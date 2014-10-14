#ifndef RENDERABLEIMAGE_H
#define RENDERABLEIMAGE_H

#include "IRenderable.h"
#include "IWidget.h"
#include <SDL2/SDL_rect.h>
#include <string>

class SDL_Texture;

class RenderableImage :public IWidget
{
public:
    RenderableImage();
    ~RenderableImage();
    void Draw(SDL_Renderer* renderer);
    bool HandleMouseEvent(Uint32 mouse_button_state, int x, int y);
    const RenderableImage& operator=( const RenderableImage& rhs );

    const SDL_Rect& GetPosition();
    void SetPosition(int x, int y);
    void SetImage(SDL_Texture* image);
    void SetSize(int w ,int h);


private:
    SDL_Texture* image;
    SDL_Rect original_dimension;
};




#endif // RENDERABLEIMAGE_H
