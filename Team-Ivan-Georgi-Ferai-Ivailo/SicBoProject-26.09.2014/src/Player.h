/*
 * Player.h
 *
 *  Created on: 20.09.2014 ã.
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
public:
	Player();
	Player(int,int,int);
	virtual ~Player();

	void nullBetAndWin();
	void setBet(int);
	void setWin(int);

	int getCredit();
	int getBet();
	int getWin();
	void setCredit(int);


};

#endif /* PLAYER_H_ */
