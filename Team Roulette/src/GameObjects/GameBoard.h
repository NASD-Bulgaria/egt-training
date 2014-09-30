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
#include "IRendable.h"

namespace GameObjects {

class GameBoard: public IRendable{
	friend class RouletteApplication;
public:
	GameBoard();
	virtual ~GameBoard();
	const std::vector<NumberSector*>& getNumberSectors() const;
	void placeHalfBet(HalfBet& halfBet);
	void placeTypeBet(TypeBet& typeBet);
	void placeNumberBet(NumberBet& numberBet);
	void placeColorBet(ColorBet& colorBet);
	int collectWinings();
	void clearAllBets();
	virtual void free();
	int getAllBetValue() const;
	NumberSector* getWiningNumberSector() const;
	void setWiningNumberSector(short winingNumber);
	virtual bool loadFromFile(SDL_Renderer* gRenderer, std::string path);
	virtual void draw(SDL_Renderer *);
	NumberSector * getClickedSector(int x, int y);
	TypeSector * getClickedTypeSector(int x, int y);
	HalfSector * getClickedHalfSector(int x, int y);
	ColorSector * getClickedColorSector(int x, int y);
	void initSectorPositions();

private:
	std::vector<NumberSector*> numberSectors;
	TypeSector * typeSectors[2];
	HalfSector * halfSectors[2];
	ColorSector * colorSectors[2];
	NumberSector* winingNumberSector;
	int allBetValue;
	const static int ROULETTESIZE = 37;
	const static Color rouletteSectorColors[ROULETTESIZE];

	void initNumberSectors();
};

} /* namespace GameObjects */

#endif /* GAMEBOARD_H_ */
