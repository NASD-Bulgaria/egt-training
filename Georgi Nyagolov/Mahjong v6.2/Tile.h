#ifndef TILE_H
#define TILE_H

enum faceType {
	FIRST,
	SECOND,
	THIRD,
	FOURTH,
	FIFTH,
	SIXTH,
	SEVENTH,
	EIGTH,
	NINGTH,
	TENTH,
	EVELENTH,
	TWELVETH,
	THIRTEENTH,
	FOURTEENTH,
	FIFTEENTH,
	NONE
};

class Tile {
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
