/*
 * ColorSector.h
 *
 *  Created on: Sep 13, 2014
 *      Author: NandM
 */

#ifndef COLORSECTOR_H_
#define COLORSECTOR_H_

#include "ColorBet.h"

namespace GameObjects {

class ColorSector : public virtual IRendable{

	friend class GameBoard;
	friend class RouletteApplication;

public:
	ColorSector(Color color);
	virtual ~ColorSector();
	Color getColor() const;
	virtual void free();
	virtual void draw(SDL_Renderer * gRenderer);
	void placeColorBet(ColorBet * colorBet);
private:
	Color color;
	ColorBet * colorBet;
};

} /* namespace GameObjects */

#endif /* COLORSECTOR_H_ */
