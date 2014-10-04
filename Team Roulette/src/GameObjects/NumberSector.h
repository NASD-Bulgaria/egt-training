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
#include "IRendable.h"
#include <sstream>

namespace GameObjects {

class NumberSector : virtual public IRendable,
					 public ColorSector,
					 public TypeSector,
					 public HalfSector{

	friend class GameBoard;
	friend class RouletteApplication;

public:
	NumberSector(short number, Color color, Type type, Half half);
	~NumberSector();
	short getNumber() const;
	void placeNumberBet(NumberBet * numberBet);
	virtual void free();
	virtual void draw(SDL_Renderer * gRenderer);
	NumberBet* getNumberBet();

private:
	short number;
	NumberBet * numberBet;
	SDL_Rect textRect;
};

} /* namespace GameObjects */

#endif /* NUMBERSECTOR_H_ */
