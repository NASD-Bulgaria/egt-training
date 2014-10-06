/*
 * HalfSector.h
 *
 *  Created on: Sep 13, 2014
 *      Author: NandM
 */

#ifndef HALFSECTOR_H_
#define HALFSECTOR_H_

#include "Sector.h"

namespace GameObjects {

#include "EnumTypes.h"

class HalfSector : public Sector{
	friend class GameBoard;
	friend class RouletteApplication;

public:
	HalfSector(Half half);
	virtual ~HalfSector();
	Half getHalf() const;
	virtual void free();
	virtual bool loadFromFile(SDL_Renderer* gRenderer, std::string path);
private:
	Half half;
};

} /* namespace GameObjects */

#endif /* HALFSECTOR_H_ */
