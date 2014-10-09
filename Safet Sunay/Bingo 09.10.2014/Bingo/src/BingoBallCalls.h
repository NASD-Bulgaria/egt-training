/*
 * BingoBallCalls.h
 *
 *  Created on: 8.10.2014 ã.
 *      Author: sony
 */

#ifndef BINGOBALLCALLS_H_
#define BINGOBALLCALLS_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;


class BingoBallCalls
{
public:
	BingoBallCalls();
	void loadBingoBalls(string);
	void fillBingoBalls(string imagePath,  vector<BingoBallCalls>& mediaContainer, BingoBallCalls obj);
	void fillBallsInVector(vector<BingoBallCalls>& mediaContainer, BingoBallCalls obj);
	void makeCall();
	void mute(unsigned);
	virtual ~BingoBallCalls();

private:
	Mix_Chunk *temp;
};

#endif /* BINGOBALLCALLS_H_ */
