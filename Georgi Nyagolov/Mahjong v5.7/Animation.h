#ifndef ANIMATION_H
#define ANIMATION_H

#include <Texture.h>

const int NUMBER_ANIMATION = 10;

class Animation : public Texture
{
    public:
        /** Default constructor */
        Animation();
        /** Default destructor */
        virtual ~Animation();

        void freeAnimation();
        bool loadAnimationFromFile( std::string path );
        void renderAnimation();
        void startAnimation(int x, int y);

    protected:
    private:
        void setPosition( int x, int y );
        void setToDefault();
        void calculateAnimation();

        SDL_Texture* animations[NUMBER_ANIMATION];
        bool start;
        Uint32 startTicks;
        SDL_Point position;
};

#endif // ANIMATION_H
