/*
 * HalfSector.h
 *
 *  Created on: Sep 13, 2014
 *      Author: NandM
 */

#ifndef HALFSECTOR_H_
#define HALFSECTOR_H_

#include "HalfBet.h"

namespace GameObjects {

#include "EnumTypes.h"

class HalfSector : public virtual IRendable{
	friend class GameBoard;
	friend class RouletteApplication;

public:
	HalfSector(Half half);
	virtual ~HalfSector();
	Half getHalf() const;
	void placeHalfBet(HalfBet * halfBet);
	virtual void free();
	virtual void draw(SDL_Renderer * gRenderer);
private:
	Half half;
	HalfBet * halfBet;
};

} /* namespace GameObjects */

#endif /* HALFSECTOR_H_ */
