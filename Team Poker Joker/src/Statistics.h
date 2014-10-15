/*
 * Statistics.h
 *
 *  Created on: 21.09.2014 г.
 *      Author: Kateto
 */

#ifndef STATISTICS_H_
#define STATISTICS_H_
#include <fstream>
#include <iostream>
#include <sstream>
#include "Credits.h"

using namespace std;

class Statistics
{
	friend class Texture;
	Credits credit;
private:

	int handsPlayed;
	int winGames;
	int lostGames;
	int creditsIn;
	int creditsWon;


public:

	Statistics ();

	void addHandsPlayed();
	void addWinGames ();
	void addLostGames();
	void addCreditsIn(int);
	void addCreditsWon(int credits);

	int getTotalPlayed();
	int getWinGames();
	int getLostGames();
	int getTotalCreditsIn();
	int getTotalCreditsWon();

	void readFromFile() ;
	void writeToFile ();
};



#endif /* STATISTICS_H_ */
