

#include "Music.h"
Music::Music()
{
}

Music::~Music() {
	closeMusic();
}

bool Music::init()
{
	bool success = true;
	if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
	{
		success = false;
		printf( "Failed to load sound media!\n" );
	}
	Mix_VolumeMusic(22);
	return success;
}

bool Music::loadMusic()
{
	bool success = true;
	init();
	music = Mix_LoadMUS( "resources/sound/music.mp3" );
	Mix_PlayMusic( music, -1 );

	chips = Mix_LoadWAV( "resources/sound/chip.wav" );
	chunks.push_back(chips);

	rollDice = Mix_LoadWAV( "resources/sound/Shake And Roll Dice.wav" );
	chunks.push_back(rollDice);

	win = Mix_LoadWAV( "resources/sound/win.wav" );
	chunks.push_back(win);

	if( music != NULL && !chips && !rollDice && win)
	{
		success = false;
		printf( "Failed to load music media!\n" );
		exit(1);
	}
	return success;
}

void Music::closeMusic()
{

	Mix_FreeChunk( chips );
	chips = NULL;
	Mix_FreeChunk( win );
	win = NULL;
	Mix_FreeChunk( rollDice );
	rollDice = NULL;
	Mix_FreeMusic( music );
	music = NULL;

	Mix_Quit();
}

void Music::playStopMusic()
{
	if (Mix_PlayingMusic() == 0)
	{
		Mix_PlayMusic( music, -1 );
	}
	else{
		Mix_HaltMusic();
	}
}


void Music::playSound()
{
	for (size_t i = 0; i < chunks.size(); ++i)
	{
		Mix_VolumeChunk(chunks[i], 128);
	}
}

void Music::stopSound()
{
	for (size_t i = 0; i < chunks.size(); ++i)
	{
		Mix_VolumeChunk(chunks[i], 0);
	}
}

void Music::playRollSound()
{
	Mix_PlayChannel( -1, chunks[1], 0 );
}

void Music::playWinSound()
{
	Mix_PlayChannel( -1, chunks[2], 0 );
}

void Music::playSetChipSound()
{
	Mix_PlayChannel( -1, chunks[0], 0 );
}
