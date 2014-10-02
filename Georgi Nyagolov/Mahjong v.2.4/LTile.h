#ifndef LTILE_H
#define LTILE_H

#include "LButton.h"
#include "Global.h"
#include "LTexture.h"
#include <sstream>
#include <vector>
#include <stack>

class LTile : public LButton
{
    friend class Board;
public:
    LTile(faceType face = NONE);
    virtual ~LTile();

    bool getblocked();
    void setblocked(bool checking);
    faceType getFace() const;
    void setFace(faceType face);
    void freeTile();
    bool handleEvent( SDL_Event e );

protected:
private:
    bool blocked;
    faceType face;
};

#endif // LTILE_H
