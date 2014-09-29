/*
 * TypeBet.h
 *
 *  Created on: Sep 12, 2014
 *      Author: NandM
 */

#ifndef TYPEBET_H_
#define TYPEBET_H_

#include "Bet.h"

namespace GameObjects {

class TypeBet: public Bet {
public:
	TypeBet(Type type, int chipCount = 1);
	virtual ~TypeBet();
	Type getType();
private:
	Type type;
	void setType(Type type);
	const static int TypeCoef = 2;
};

} /* namespace GameObjects */

#endif /* TYPEBET_H_ */
