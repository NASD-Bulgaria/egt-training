/*
 * NumberSector.h
 *
 *  Created on: Sep 12, 2014
 *      Author: NandM
 */

#ifndef NUMBERSECTOR_H_
#define NUMBERSECTOR_H_

#include "ColorSector.h"
#include "TypeSector.h"
#include "HalfSector.h"
#include "NumberBet.h"

namespace GameObjects {

class NumberSector : public ColorSector,
					 public TypeSector,
					 public HalfSector{

	friend class GameBoard;

public:
	NumberSector(short number, Color color, Type type, Half half);
	~NumberSector();
	short getNumber() const;
	void placeNumberBet(NumberBet * numberBet);
private:
	short number;
	NumberBet * numberBet;
};

} /* namespace GameObjects */

#endif /* NUMBERSECTOR_H_ */
