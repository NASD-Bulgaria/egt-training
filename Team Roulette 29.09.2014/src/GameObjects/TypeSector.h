/*
 * TypeSector.h
 *
 *  Created on: Sep 13, 2014
 *      Author: NandM
 */

#ifndef TYPESECTOR_H_
#define TYPESECTOR_H_

#include "TypeBet.h"

namespace GameObjects {

class TypeSector : public virtual IRendable{

	friend class GameBoard;
	friend class RouletteApplication;

public:
	TypeSector(Type type);
	virtual ~TypeSector();
	Type getType() const;
	void placeTypeBet(TypeBet * typeBet);
	virtual void free();
	virtual void draw(SDL_Renderer * gRenderer);
private:
	Type type;
	TypeBet * typeBet;
};

} /* namespace GameObjects */

#endif /* TYPESECTOR_H_ */
