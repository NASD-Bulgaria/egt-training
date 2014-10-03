#ifndef LTILE_H
#define LTILE_H

#include "LButton.h"
#include "Global.h"

class LTile : public LButton
{
    friend class Board;
public:
    LTile(faceType face = NONE);
    virtual ~LTile();

    bool getBlocked();
    void setBlocked(bool checking);
    faceType getFace() const;
    void setFace(faceType face);
    void freeTile();
    bool handleEvent( SDL_Event e, int &coordI, int &coordJ);

    struct tileCoordinates
    {
        int i,j;
    }coordinates;

protected:
private:
    bool blocked;
    bool mark;
    faceType face;
};

#endif // LTILE_H
