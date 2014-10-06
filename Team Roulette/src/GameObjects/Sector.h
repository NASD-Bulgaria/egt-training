/*
 * Sector.h
 *
 *  Created on: Oct 5, 2014
 *      Author: NandM
 */

#ifndef SECTOR_H_
#define SECTOR_H_

#include "Bet.h"
namespace GameObjects {

class Sector: public IRendable {
	friend class GameBoard;
	friend class RouletteApplication;
public:
	Sector();
	virtual ~Sector();
	void placeBet(Bet* bet);
	virtual void free();
	virtual void draw(SDL_Renderer * gRenderer);
protected:
	Bet * bet;
};

} /* namespace GameObjects */

#endif /* SECTOR_H_ */
