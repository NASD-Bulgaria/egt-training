/*
 * Ball.h
 *
 *  Created on: Oct 6, 2014
 *      Author: NandM
 */

#ifndef BALL_H_
#define BALL_H_

#include "IRendable.h"
#include "EnumTypes.h"
#include "cmath"
#include "ctime"
#include "cstdlib"

namespace GameObjects {

class Ball: public IRendable {
	friend class RouletteBoard;
public:
	Ball();
	virtual ~Ball();
	int getXCenter() const;
	void setXCenter(int center);
	int getYCenter() const;
	void setYCenter(int center);
	virtual void setPosition(int x, int y);
	void initBall(int xCenter, int yCenter, int maxRadius, int minRadius);
	void moove(RouletteWheelState rouletteSpeed);
	bool isInSector() const;
	void setInSector(bool inSector);

private:
	double maxRadius;
	double minRadius;
	double currentRadius;
	double angle;
	double maxAngle;
	int xCenter;
	int yCenter;
	bool inSector;
};

} /* namespace GameObjects */

#endif /* BALL_H_ */
