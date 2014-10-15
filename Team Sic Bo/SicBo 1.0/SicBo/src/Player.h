/*
 * Player.h
 *
 *  Created on: 2.10.2014 ã.
 *      Author: msi
 */

#ifndef PLAYER_H_
#define PLAYER_H_

class Player
{
protected:
	int credit;
	int bet;
	int win;
	int showWin;
public:
	Player();
	Player(int,int,int);
	virtual ~Player();

	void nullPlayerStatistic();

	void setBet(int);
	void setWin(int);
	void setShowWin(int);

	int getShowWin();
	int getCredit();
	int getBet();
	int getWin();

	int showCredit();
	void setCredit(int);
//	void checkCredit(Player &);

};

#endif /* PLAYER_H_ */
