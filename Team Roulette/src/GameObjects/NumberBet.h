/*
 * NumberBet.h
 *
 *  Created on: Sep 16, 2014
 *      Author: NandM
 */

#ifndef NUMBERBET_H_
#define NUMBERBET_H_

#include "Bet.h"

namespace GameObjects {

class NumberBet: public Bet {
public:
	NumberBet(short number, int chipCount = 1);
	virtual ~NumberBet();
	short getNumber();
	void setNumber(short num);
private:
	short number;

	const static int NumberCoef = 36;
};

} /* namespace GameObjects */

#endif /* NUMBERBET_H_ */
