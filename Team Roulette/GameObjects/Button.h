/*
 * Button.h
 *
 *  Created on: Oct 11, 2014
 *      Author: NandM
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "IRendable.h"
#include "EnumTypes.h"

namespace GameObjects {

class Button: public IRendable {
public:
	Button(int x = 0, int y = 0, GameState alowedState = PlayState);
	virtual bool isClicked(int x, int y, GameState currentState);
	virtual ~Button();
	GameState getAllowedState();
private:
	const GameState alowedState;
};

} /* namespace GameObjects */

#endif /* BUTTON_H_ */
