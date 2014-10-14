/*
 * Button.cpp
 *
 *  Created on: Oct 11, 2014
 *      Author: NandM
 */

#include "Button.h"

namespace GameObjects {

Button::Button(int x, int y, GameState alowedState)
	:IRendable(x,y), alowedState(alowedState){
}

bool Button::isClicked(int x, int y, GameState currentState) {
	if (currentState == alowedState) {
		if (x >= getX() && x <= getWidth() + getX() && y >= getY()
				&& y <= getY() + getHeight()) {
			return true;
		}
	}
	return false;
}

Button::~Button() {
	// TODO Auto-generated destructor stub
}

GameState Button::getAllowedState() {
	return this->alowedState;
}

} /* namespace GameObjects */
