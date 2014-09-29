/*
 * Bet.h
 *
 *  Created on: Sep 12, 2014
 *      Author: NandM
 */

#ifndef BET_H_
#define BET_H_

#include <cstdlib>

namespace GameObjects {

#include "EnumTypes.h"

class Bet {
public:
	Bet(int winCoef, int credits = 5);
	virtual ~Bet();
	int getCoef();
	int getCredits();
private:
	int winCoef;
	int credits;
};

} /* namespace GameObjects */

#endif /* BET_H_ */
