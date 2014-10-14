/*
 * Sound.cpp
 *
 *  Created on: 04.10.2014
 *      Author: Koko
 */

#include "Sound.h"

Sound::Sound()
{
	soundEffects = false;
	music = false;
	gMusic = NULL;

	soundBeep = NULL;
	gScratch = NULL;
	gWin = NULL;
	gLoose = NULL;

}

bool Sound::loadSoundAndMusic()
{
	bool success = true;
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n",
				Mix_GetError());
		success = false;
	}
	soundBeep = Mix_LoadWAV("Media/SoundBeep.wav");
	if (soundBeep == NULL)
	{
		printf("Failed to load beep sound effect! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}
	gScratch = Mix_LoadWAV("Media/scratch.wav");
	if (gScratch == NULL)
	{
		printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}
	gMusic = Mix_LoadWAV("Media/Theme.wav");
	if (gMusic == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}
	gWin = Mix_LoadWAV("Media/win.wav");
	if (gWin == NULL)
	{
		printf("Failed to load win sound effect! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}
	gLoose = Mix_LoadWAV("Media/loose.wav");
	if (gLoose == NULL)
	{
		printf("Failed to load loose sound effect! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}
	return success;
}

void Sound::SoundBeep()
{
	Mix_PlayChannel(1, soundBeep, 0);
}

void Sound::SoundScratch()
{
	Mix_PlayChannel(2, gScratch, 0);
}

void Sound::SoundWin()
{
	Mix_PlayChannel(3, gWin, 0);
}

void Sound::SoundLoose()
{
	Mix_PlayChannel(4, gLoose, 0);
}

void Sound::SoundMute()
{
	soundBeep->volume = 0;
	gScratch->volume = 0;
	gWin->volume = 0;
	gLoose->volume = 0;
}

void Sound::SoundUnMute()
{
	soundBeep->volume = 100;
	gScratch->volume = 100;
	gWin->volume = 100;
	gLoose->volume = 100;
}

void Sound::startMusic()
{
	gMusic->volume = 80;
	Mix_PlayChannel(5, gMusic, -1);
}

void Sound::stopMusic()
{
	gMusic->volume = 0;
}

Sound::~Sound()
{
	Mix_FreeChunk(gScratch);
	Mix_FreeChunk(soundBeep);
	Mix_FreeChunk(gWin);
	Mix_FreeChunk(gLoose);
	Mix_FreeChunk(gMusic);
	Mix_Quit();
}
