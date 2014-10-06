/*
 * Sound.h
 *
 *  Created on: 04.10.2014
 *      Author: Koko
 */

#ifndef SOUND_H_
#define SOUND_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>

class Sound
{
public:
	Sound();
	bool loadSoundAndMusic();
	void SoundBeep();
	void SoundScratch();
	void SoundWin();
	void SoundLoose();

	void SoundMute();
	void SoundUnMute();

	void startMusic();
	void stopMusic();
	virtual ~Sound();
private:
	bool soundEffects;
	bool music;
	Mix_Chunk *gMusic;

	Mix_Chunk *soundBeep;
	Mix_Chunk *gScratch;
	Mix_Chunk *gWin;
	Mix_Chunk *gLoose;
};

#endif /* SOUND_H_ */
