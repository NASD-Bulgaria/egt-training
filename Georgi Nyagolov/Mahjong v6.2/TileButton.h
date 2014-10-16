#ifndef LTILE_H
#define LTILE_H

#include "Button.h"
#include "Tile.h"

class TileButton: public Button {
public:
	TileButton(faceType face = NONE);
	virtual ~TileButton();

	bool getBlocked();
	void setBlocked(bool checking);

	faceType getFace() const;
	void setFace(faceType face);
	void freeTile();
	bool handleEvent(SDL_Event e, int &coordI, int &coordJ);

	struct tileCoordinates {
		int i, j;
	} coordinates;

protected:
private:
	bool blocked;
	faceType face;
};

#endif // LTILE_H
