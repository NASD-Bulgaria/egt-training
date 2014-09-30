/*
 * RouletteWheel.h
 *
 *  Created on: Sep 18, 2014
 *      Author: NandM
 */

#ifndef ROULETTEWHEEL_H_
#define ROULETTEWHEEL_H_

#include "EnumTypes.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
namespace GameObjects {

class RouletteWheel {
	friend class RouletteApplication;
public:
	RouletteWheel();
	void spin();
	virtual ~RouletteWheel();
	RouletteWheelState getSpinSpeed() const;
	short getWiningNumber();
	double getCurrentDegrees();
	void initiate();
private:
	RouletteWheelState spinSpeed;
	double spinTime;
	double speedInterval;
	double currentDegrees;
	short currentNumberIndex;

	static double numbersDegrees[37][2];
};

} /* namespace GameObjects */

#endif /* ROULETTEWHEEL_H_ */
