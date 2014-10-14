/*
 * RouletteBoard.h
 *
 *  Created on: Oct 7, 2014
 *      Author: NandM
 */

#ifndef ROULETTEBOARD_H_
#define ROULETTEBOARD_H_

#include "IRendable.h"
#include "Ball.h"
#include "RouletteWheel.h"

namespace GameObjects {
class RouletteBoard: public IRendable {
	friend class RouletteApplication;
public:
	RouletteBoard(int x = 0, int y = 0);
	virtual bool loadFromFile(SDL_Renderer* gRenderer, std::string path);
	virtual void draw(SDL_Renderer*);
	virtual void setPosition(int x, int y);
	virtual void free();
	short getWininngNumber();
	void initRouletteBoard();
	int getRadius();
	void resetWiningNumber();
	virtual ~RouletteBoard();
//private:
	RouletteWheel* wheel;
	short currentNumberIndex;
	Ball* ball;
	void handleBallInSector();
	void initNumberDegrees();
	static double numbersDegrees[37][3];
};

} /* namespace GameObjects */

#endif /* ROULETTEBOARD_H_ */
