/*
 * BingoTicket.h
 *
 *  Created on: 18.09.2014
 *      Author:
 */

#ifndef BINGOTICKET_H_
#define BINGOTICKET_H_

#include "GlobalVariables.h"

using namespace std;

class BingoTicket
{
public:
	BingoTicket();
	virtual ~BingoTicket();
	void drawNewTicket();
	void putOnScreen(int xPos, int yPos);
	void fill(int, int, int);
	void clearTicket(vector<int> &tmp);
	string ticket[5][5];
private:
	vector<int> b;
	vector<int> i;
	vector<int> n;
	vector<int> g;
	vector<int> o;
};

#endif /* BINGOTICKET_H_ */
