/*
 * Bet.h
 *
 *  Created on: Sep 12, 2014
 *      Author: NandM
 */

#ifndef BET_H_
#define BET_H_

#include <cstdlib>

#include "EnumTypes.h"
#include "IRendable.h"
namespace GameObjects {


class Bet : public IRendable{
public:
	Bet(int winCoef, int credits = 5);
	virtual ~Bet();
	int getCoef();
	int getCredits();
	void setCredits(int credits);
private:
	int winCoef;
	int credits;
};

} /* namespace GameObjects */

#endif /* BET_H_ */
