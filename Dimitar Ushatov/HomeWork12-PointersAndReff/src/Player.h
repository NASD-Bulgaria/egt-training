/*
 * Player.h
 *
 *  Created on: Aug 11, 2014
 *      Author: NandM
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "Card.h"
#include <vector>
#include "HandCondition.h"

class Player {
public:
	Player();
	virtual ~Player();

	PowerOfHands getPowerOfHand() const;

	void addCard(Card&);

	const vector<Card> getHand() const;

private:
	vector<Card> hand;
	PowerOfHands powerOfHand;
	void setPowerOfHand(vector<bool(*)(vector<Card>)>);
};

#endif /* PLAYER_H_ */
