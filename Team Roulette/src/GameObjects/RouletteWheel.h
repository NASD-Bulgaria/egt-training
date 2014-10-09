/*
 * RouletteWheel.h
 *
 *  Created on: Sep 18, 2014
 *      Author: NandM
 */

#ifndef ROULETTEWHEEL_H_
#define ROULETTEWHEEL_H_

#include "EnumTypes.h"
#include "IRendable.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
namespace GameObjects {

class RouletteWheel : public IRendable{
	friend class RouletteApplication;
public:
	RouletteWheel();
	void spin();
	virtual ~RouletteWheel();
	RouletteWheelState getSpinSpeed() const;
	virtual void draw(SDL_Renderer* gRenderer);
	int getRadius();
	int getXCenter();
	int getYCenter();
	double getSpinAngle();
	void initiate();
private:
	RouletteWheelState spinSpeed;
	double spinAngle;
	double maxSpinAngle;
	double spinInterval;
};

} /* namespace GameObjects */

#endif /* ROULETTEWHEEL_H_ */
