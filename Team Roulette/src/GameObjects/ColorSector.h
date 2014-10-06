/*
 * ColorSector.h
 *
 *  Created on: Sep 13, 2014
 *      Author: NandM
 */

#ifndef COLORSECTOR_H_
#define COLORSECTOR_H_

#include "Sector.h"

namespace GameObjects {

class ColorSector : public Sector{

	friend class GameBoard;
	friend class RouletteApplication;

public:
	ColorSector(Color color);
	virtual ~ColorSector();
	Color getColor() const;
	virtual bool loadFromFile(SDL_Renderer* gRenderer, std::string path);
private:
	Color color;
};

} /* namespace GameObjects */

#endif /* COLORSECTOR_H_ */
