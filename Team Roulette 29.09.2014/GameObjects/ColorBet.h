/*
 * ColorBet.h
 *
 *  Created on: Sep 12, 2014
 *      Author: NandM
 */

#ifndef COLORBET_H_
#define COLORBET_H_

#include "Bet.h"

namespace GameObjects {

class ColorBet: public Bet {
public:
	ColorBet(Color betOnColor, int chipCount = 1);
	virtual ~ColorBet();
	Color getColor();
private:
	Color betOnColor;
	void setColor(Color color);

	static const int ColorCoef = 2;
};

} /* namespace GameObjects */

#endif /* COLORBET_H_ */
