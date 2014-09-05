/*
 * HandCondition.h
 *
 *  Created on: Aug 11, 2014
 *      Author: NandM
 */

#ifndef HANDCONDITION_H_
#define HANDCONDITION_H_

#include <vector>
#include "Card.h"

using namespace std;

class HandCondition {
public:
	virtual ~HandCondition();

	static HandCondition Checker();

	const vector<bool (*)(vector<Card>)>& getConditions() const;

	void declareWinner();

private:
	static bool compareCards(Card first, Card second);

	static bool hasFlush(vector<Card> cards);

	static bool hasStaight(vector<Card> cards);

	static bool hasStaightFlush(vector<Card> cards);

	static bool hasFourOfAKind(vector<Card> cards);

	static bool hasFullHouse(vector<Card> cards);

	static bool hasThreeOfAKind(vector<Card> cards);

	static bool hasTwoPairs(vector<Card> cards);

	static bool hasOnePair(vector<Card> cards);

	HandCondition();

	vector<bool(*)(vector<Card>)> conditions;
};

#endif /* HANDCONDITION_H_ */
