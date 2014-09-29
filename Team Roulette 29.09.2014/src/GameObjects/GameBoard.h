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

namespace GameObjects {

class GameBoard {
public:
	GameBoard();
	virtual ~GameBoard();
	const ColorSector* getBlackSector() const;
	const TypeSector* getEvenSector() const;
	const HalfSector* getHighSector() const;
	const HalfSector* getLowSector() const;
	const TypeSector* getOddSector() const;
	const ColorSector* getRedSector() const;
	const std::vector<NumberSector*>& getNumberSectors() const;
	void placeHalfBet(HalfBet& halfBet);
	void placeTypeBet(TypeBet& typeBet);
	void placeNumberBet(NumberBet& numberBet);
	void placeColorBet(ColorBet& colorBet);
	int collectWinings();
	void clearAllBets();
	int getAllBetValue() const;
	NumberSector* getWiningNumberSector() const;
	void setWiningNumberSector(short winingNumber);

private:
	std::vector<NumberSector*> numberSectors;
	TypeSector * oddSector;
	TypeSector * evenSector;
	HalfSector * lowSector;
	HalfSector * highSector;
	ColorSector * blackSector;
	ColorSector * redSector;
	int allBetValue;
	const static int ROULETTESIZE = 37;
	NumberSector* winingNumberSector;
	const static Color rouletteSectorColors[ROULETTESIZE];

	void initNumberSecotrs();
};

} /* namespace GameObjects */

#endif /* GAMEBOARD_H_ */
