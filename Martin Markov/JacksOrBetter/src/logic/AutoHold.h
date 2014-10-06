/*
 * AutoHold.h
 *
 *  Created on: Sep 19, 2014
 *      Author: Keen
 */

#ifndef AUTOHOLD_H_
#define AUTOHOLD_H_

#include "Card.h"
#include "Deck.h"

#include <vector>
#include <algorithm>
using namespace std;

class AutoHold
{
private:
	int suite [4];
	int face [13];

	void holdFace(vector<Card>&, vector<bool>&, int, bool);
public:
	AutoHold();

	void getMarkup(vector<Card>&, vector<bool>&);

	int getScore(vector<Card>, int = 1);

	~AutoHold();
};

#endif /* AUTOHOLD_H_ */
