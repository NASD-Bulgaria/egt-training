#include "LTile.h"

LTile::LTile()
:checkTile(false)
{
    //ctor
}

LTile::~LTile()
{
    //dtor
}

bool LTile::GetcheckTile()
{
    return checkTile;
}
void LTile::SetcheckTile(bool checking)
{
    checkTile = checking;
}

void LTile::freeTile()
{
    freeButton();
}
