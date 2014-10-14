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
	int *index;

	void holdFace(vector<Card>&, vector<bool>&, int, bool);
	void holdSuite(vector<Card>&, vector<bool>&, int, bool);
	bool isRoyalFlush(int = 5);
	bool isStraightFlush(int = 5);
	bool isFlush(int = 5);
	bool isStraight(int = 5);
	bool isFullHouse();
	bool isFour();
	bool isThree();
	bool isPairs(int = 2);
public:
	AutoHold();

	void getMarkup(vector<Card>&, vector<bool>&);

	int getScore(vector<Card>, int = 1);

	~AutoHold();
};

#endif /* AUTOHOLD_H_ */
