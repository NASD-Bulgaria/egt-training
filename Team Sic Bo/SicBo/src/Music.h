
#ifndef MUSIC_H_
#define MUSIC_H_
#include <SDL2/SDL_mixer.h>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;
class Music
{

	Mix_Music *music = NULL;
	Mix_Chunk *chips = NULL;
	Mix_Chunk *rollDice = NULL;
	Mix_Chunk *win = NULL;
	vector<Mix_Chunk *> chunks;
public:
	Music();
	virtual ~Music();
	bool init();
	bool loadMusic();
	void closeMusic();
	void playStopMusic();
	void playSound();
	void stopSound();
	void playRollSound();
	void playWinSound();
	void playSetChipSound();
};

#endif /* MUSIC_H_ */
