/*
 * GameBoard.h
 *
 *  Created on: Sep 16, 2014
 *      Author: NandM
 */

#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

#include <vector>
#include "NumberSector.h"
#include "TypeSector.h"
#include "HalfSector.h"
#include "ColorSector.h"

namespace GameObjects {

class GameBoard: public IRendable{
	friend class RouletteApplication;
public:
	GameBoard();
	virtual ~GameBoard();
	const std::vector<NumberSector*>& getNumberSectors() const;
	int collectWinings();
	void clearAllBets();
	NumberSector* getWiningNumberSector() const;
	void setWiningNumberSector(short winingNumber);
	virtual void free();
	virtual bool loadFromFile(SDL_Renderer* gRenderer, std::string path);
	virtual void draw(SDL_Renderer *);
	virtual void setPosition(int x, int y);
	bool anyBetPlaced();

//private:
	vector<NumberSector*> numberSectors;
	vector<Sector*> betSectors;
	vector<Sector*> allSectors;
	vector<TypeSector*> getTypeSectors();
	vector<HalfSector*> getHalfSectors();
	vector<ColorSector*> getColorSectors();
	NumberSector* winingNumberSector;
	const static int ROULETTESIZE = 37;
	const static Color rouletteSectorColors[ROULETTESIZE];
	void initNumberSectors();
	void initBetSectors();
};

} /* namespace GameObjects */

#endif /* GAMEBOARD_H_ */
