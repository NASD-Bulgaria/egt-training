/*
 * Ball.cpp
 *
 *  Created on: Oct 6, 2014
 *      Author: NandM
 */

#include "Ball.h"

namespace GameObjects {

Ball::Ball() {
	setXCenter(xCenter);
	setYCenter(yCenter);
	initBall(0, 0, 0, 0);
	angle = 0;
}

Ball::~Ball() {
	IRendable::free();
}

int Ball::getXCenter() const {
	return xCenter;
}

void Ball::setXCenter(int center) {
	xCenter = center;
}

int Ball::getYCenter() const {
	return yCenter;
}

void Ball::setYCenter(int center) {
	yCenter = center;
}

void Ball::setPosition(int x, int y) {
	rect.x = x - getWidth() / 2;
	rect.y = y - getHeight() / 2;
}

void Ball::initBall(int xCenter, int yCenter, int maxRadius, int minRadius) {
	this->maxRadius = maxRadius;
	this->minRadius = minRadius;
	setXCenter(xCenter);
	setYCenter(yCenter);
	currentRadius = maxRadius;
	while(angle >= 2.0 * M_PI){
		angle -= 2.0 * M_PI;
	}
	maxAngle = angle + 5.0 *(2.0 * M_PI) + (rand() % (int)(M_PI * 2000)) / 1000.0;
	inSector = false;
}

void Ball::moove(RouletteWheelState rouletteSpeed) {
	if (rouletteSpeed != Stoped) {
		if (inSector) {
			angle -= rouletteSpeed / (360.0 / M_PI);
		} else {
			angle += (currentRadius - minRadius) / (7.0 * 180.0 / M_PI);
			if (angle > maxAngle) {
				currentRadius -= (maxRadius - minRadius) / ( 14.0 * 180.0 / M_PI);
			}
			if (currentRadius <= minRadius) {
				inSector = true;
			}
		}
		setPosition(xCenter + currentRadius * sin(angle),
				yCenter + currentRadius * cos(angle));
	}
}

bool Ball::isInSector() const {
	return inSector;
}

void Ball::setInSector(bool inSector) {
	this->inSector = inSector;
}

} /* namespace GameObjects */
