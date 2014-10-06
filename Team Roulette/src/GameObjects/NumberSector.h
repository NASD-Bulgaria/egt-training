/*
 * NumberSector.h
 *
 *  Created on: Sep 12, 2014
 *      Author: NandM
 */

#ifndef NUMBERSECTOR_H_
#define NUMBERSECTOR_H_

#include "Sector.h"
#include <sstream>

namespace GameObjects {

class NumberSector : public Sector{

	friend class GameBoard;
	friend class RouletteApplication;

public:
	NumberSector(short number, Color color, Type type, Half half);
	~NumberSector();
	short getNumber() const;
	virtual bool loadFromFile(SDL_Renderer* gRenderer, std::string path);
	Color getColor() const;
	Half getHalf() const;
	Type getType() const;

private:
	short number;
	Color color;
	Type type;
	Half half;
};

} /* namespace GameObjects */

#endif /* NUMBERSECTOR_H_ */
