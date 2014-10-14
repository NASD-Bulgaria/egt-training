/*
 * BingoBallCalls.cpp
 *
 *  Created on: 8.10.2014 ã.
 *      Author: sony
 */

#include "BingoBallCalls.h"

BingoBallCalls::BingoBallCalls()
{
	temp = NULL;
}

void BingoBallCalls::loadBingoBalls(string path)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n",
				Mix_GetError());
	}
	temp = Mix_LoadWAV(path.c_str());
	if (temp == NULL)
	{
		printf("Failed to load sound effect! SDL_mixer Error: %s\n",
		Mix_GetError());
	}
	temp->volume = 120;
}

void BingoBallCalls::fillBingoBalls(string path, vector<BingoBallCalls>& mediaContainer, BingoBallCalls obj)
{
	obj.loadBingoBalls(path.c_str());

	mediaContainer.push_back(obj);
}

void BingoBallCalls::fillBallsInVector(vector<BingoBallCalls>& mediaContainer,	BingoBallCalls obj)
{
	fillBingoBalls("CallChunks/1.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/2.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/3.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/4.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/5.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/6.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/7.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/8.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/9.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/10.wav", mediaContainer, obj);

	fillBingoBalls("CallChunks/11.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/12.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/13.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/14.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/15.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/16.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/17.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/18.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/19.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/20.wav", mediaContainer, obj);

	fillBingoBalls("CallChunks/21.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/22.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/23.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/24.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/25.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/26.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/27.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/28.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/29.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/30.wav", mediaContainer, obj);

	fillBingoBalls("CallChunks/31.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/32.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/33.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/34.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/35.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/36.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/37.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/38.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/39.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/40.wav", mediaContainer, obj);

	fillBingoBalls("CallChunks/41.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/42.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/43.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/44.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/45.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/46.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/47.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/48.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/49.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/50.wav", mediaContainer, obj);

	fillBingoBalls("CallChunks/51.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/52.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/53.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/54.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/55.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/56.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/57.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/58.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/59.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/60.wav", mediaContainer, obj);

	fillBingoBalls("CallChunks/61.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/62.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/63.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/64.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/65.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/66.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/67.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/68.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/69.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/70.wav", mediaContainer, obj);

	fillBingoBalls("CallChunks/71.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/72.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/73.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/74.wav", mediaContainer, obj);
	fillBingoBalls("CallChunks/75.wav", mediaContainer, obj);

}

void BingoBallCalls::mute(unsigned mute)
{
	temp->volume = 200*mute;
}

void BingoBallCalls::makeCall()
{
	Mix_PlayChannel(6, temp, 0);
}

BingoBallCalls::~BingoBallCalls()
{
}
