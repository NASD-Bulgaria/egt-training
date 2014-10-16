/*
 * TypeSector.h
 *
 *  Created on: Sep 13, 2014
 *      Author: NandM
 */

#ifndef TYPESECTOR_H_
#define TYPESECTOR_H_

#include "Sector.h"

namespace GameObjects {

class TypeSector : public Sector{

	friend class GameBoard;
	friend class RouletteApplication;

public:
	TypeSector(Type type);
	virtual ~TypeSector();
	Type getType() const;
	virtual bool loadFromFile(SDL_Renderer* gRenderer, std::string path);
private:
	Type type;
};

} /* namespace GameObjects */

#endif /* TYPESECTOR_H_ */
