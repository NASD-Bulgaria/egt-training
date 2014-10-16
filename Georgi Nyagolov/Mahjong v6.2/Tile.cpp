#include "Tile.h"

Tile::Tile(faceType face)
{
    blocked = true;
    this->face = face;
}

Tile::~Tile()
{
    //dtor
}

bool Tile::getBlocked()
{
    return blocked;
}
void Tile::setBlocked(bool checking)
{
    blocked = checking;
}

faceType Tile::getFace() const
{
    return face;
}

void Tile::setFace(faceType face)
{
    this->face = face;
}



