#ifndef TILE_H
#define TILE_H

#include "Global.h"

class Tile
{
    friend class Board;
public:
    Tile(faceType face = NONE);
    virtual ~Tile();

    bool getBlocked();
    void setBlocked(bool checking);
    faceType getFace() const;
    void setFace(faceType face);

protected:
private:
    bool blocked;
    faceType face;
};

#endif // TILE_H
