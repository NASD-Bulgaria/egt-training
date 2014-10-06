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
	Bet(int winCoef, int credits);
	virtual ~Bet();
	int getCoef();
	int getCredits();
	void setCredits(int amount);
	virtual bool loadFromFile(SDL_Renderer* gRenderer, std::string path);
	void increaseCredits(int amount);
	bool decreaseCredits(int amount);
private:
	int winCoef;
	int credits;
};

} /* namespace GameObjects */

#endif /* BET_H_ */
