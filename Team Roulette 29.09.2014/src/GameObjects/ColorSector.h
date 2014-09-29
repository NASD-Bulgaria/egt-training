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

class ColorSector {

	friend class GameBoard;

public:
	ColorSector(Color color);
	virtual ~ColorSector();
	Color getColor() const;
	void placeColorBet(ColorBet * colorBet);
private:
	Color color;
	ColorBet * colorBet;
};

} /* namespace GameObjects */

#endif /* COLORSECTOR_H_ */
