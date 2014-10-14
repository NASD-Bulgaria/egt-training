#include "AutoHold.h"

AutoHold::AutoHold()
{
}

void AutoHold::holdSuite(vector<Card>& hand, vector<bool>& hold, int index, bool equal)
{
	if(equal)
	{
		for(int i=0; i<5; i++)
			if(hand[i].getSuit() == index)
			{
				hold[i] = false;
				return;
			}
	}
	else
	{
		for(int i=0; i<5; i++)
			if(hand[i].getSuit() != index)
				hold[i] = false;
	}
}

void AutoHold::holdFace(vector<Card>&hand, vector<bool>&hold, int index, bool equal)
{
	if(equal)
	{
		for(int i=0; i<5; i++)
			if(hand[i].getFace() == index)
			{
				hold[i] = false;
				return;
			}
	}
	else
	{
		for(int i=0; i<5; i++)
			if(hand[i].getFace() != index)
				hold[i] = false;
	}
}

bool AutoHold::isFlush(int index)
{
	return *max_element(suite, suite+4)>=index;
}

bool AutoHold::isStraight(int index)
{
	for(int i=0; i<9; i++)
		if(count(face+i, face+i+5, 0) <= 5-index)
			return true;

	if(face[12] == 1 && count(face, face+4, 0) == 4-(index-1))
		return true;

	return false;
}

bool AutoHold::isRoyalFlush(int index)
{
	return (isFlush(index) && count(face+8, face+13, 0) <= 5-index);
}

bool AutoHold::isStraightFlush(int index)
{
	return (isFlush(index) && isStraight(index));
}

bool AutoHold::isThree()
{
	return count(face, face+13, 3) == 1;
}

bool AutoHold::isPairs(int index)
{
	return count(face, face+13, 2) == index;
}

bool AutoHold::isFullHouse()
{
	return (isThree() && isPairs(1));
}

bool AutoHold::isFour()
{
	return count(face, face+13, 4) == 1;
}

void AutoHold::getMarkup(vector<Card> &hand, vector<bool> &hold)
{
	fill(suite, suite+4, 0);
	fill(face, face+13, 0);

	for(unsigned i=0; i<hand.size(); i++)
	{
		suite[hand[i].getSuit()]++;
		face[hand[i].getFace()]++;
	}

    if(isRoyalFlush())
		return;

    if(isStraightFlush())
        return;

	if(isFour())
	{
		index = find(face, face+13, 1);
		holdFace(hand, hold, (index-face), true);
			return;
	}

	if(isRoyalFlush(4))
	{
		if(!isStraight()|| count(face+8, face+13, 1)==5)
		{
			if(count(suite, suite+4, 1) == 1)
			{
				index = find(suite, suite+4, 1);
				holdSuite(hand, hold, (index-suite), true);
				return;
			}

			index = find(face, face+8, 1);
			holdFace(hand, hold, (index-face), true);
			return;
		}
	}

    if(isFullHouse())
		return;

    if(isFlush())
        return;

    if(isStraight())
        return;

	if(isThree())
	{
		index = find(face, face+13, 3);
		holdFace(hand, hold, (index-face), false);
		return;
	}

	if(isPairs())
	{
		index = find(face, face+13, 1);
		holdFace(hand, hold, (index-face), true);
		return;
	}

	if(isStraightFlush(4))
	{
		if(count(suite, suite+4, 1) == 1)
		{
			index = find(suite, suite+4, 1);
			holdSuite(hand, hold, (index-suite), true);
			return;
		}

	}

	if(isPairs(1))
	{
		index = find(face, face+13, 2);
		holdFace(hand, hold, (index-face), false);
		return;
	}

	index = find(suite, suite+4, 2);
	if(count(face+9, face+13, 1)>=2 && (index-suite) < 4)
	{
		while((index-suite) < 4)
		{
			int count = 0;
			for(int i=0; i<5; ++i)
				if(hand[i].getSuit() == (index-suite) && hand[i].getFace()>8)
					count++;

			if(count == 2)
            {
				holdSuite(hand, hold, (index-suite), false);
                return;
            }
			count=0;

			index++;
			index = find(index, suite+4, 2);
		}

	}

	fill(hold.begin(), hold.end(), false);
}


int AutoHold::getScore(vector<Card> hand, int bet)
{
	fill(suite, suite+4, 0);
	fill(face, face+13, 0);
	for(unsigned i=0; i<hand.size(); i++)
	{
		suite[hand[i].getSuit()]++;
		face[hand[i].getFace()]++;
	}

	if(isRoyalFlush())
		return 250*bet;

	if(isStraightFlush())
		return 50*bet;

	if(isFour())
		return 25*bet;

	if(isFullHouse())
		return 9*bet;

	if(isFlush())
		return 6*bet;

	if(isStraight())
		return 4*bet;

	if(isThree())
		return 3*bet;

	if(isPairs(2))
		return 2*bet;

	if(isPairs(1))
	{
		index = find(face, face+13, 2);
		if((index-face) > 8)
			return 1*bet;
	}

	return 0;
}

AutoHold::~AutoHold() {
	// TODO Auto-generated destructor stub
}



