/*
 * HalfBet.h
 *
 *  Created on: Sep 16, 2014
 *      Author: NandM
 */

#ifndef HALFBET_H_
#define HALFBET_H_

#include "Bet.h"

namespace GameObjects {

class HalfBet: public Bet {
public:
	HalfBet(Half half, int chipCount = 1);
	virtual ~HalfBet();
	Half getHalf();
private:
	Half half;
	void setHalf(Half half);

	static const int HalfCoef = 2;
};

} /* namespace GameObjects */

#endif /* HALFBET_H_ */
