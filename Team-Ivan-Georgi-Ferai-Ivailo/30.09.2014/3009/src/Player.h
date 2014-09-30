/*
 * Player.h
 *
 *  Created on: 20.09.2014 �.
 *      Author: msi
 */

#ifndef PLAYER_H_
#define PLAYER_H_

class Player
{
private:
	int credit;
	int bet;
	int win;
	int showWin;
public:
	Player();
	Player(int,int,int);
	virtual ~Player();

	void nullBet();
	void nullWin();
	void setBet(int);
	void setWin(int);
	void setShowWin(int);

	int getShowWin();
	int getCredit();
	int getBet();
	int getWin();
	int showCredit();
	void setCredit(int);


};

#endif /* PLAYER_H_ */
