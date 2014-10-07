/*
 * AutoHold.cpp
 *
 *  Created on: Sep 19, 2014
 *      Author: Keen
 */

#include "AutoHold.h"

AutoHold::AutoHold()
{
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

void AutoHold::getMarkup(vector<Card> &hand, vector<bool> &hold)
{
	fill(suite, suite+4, 0);
	fill(face, face+13, 0);

	int *index;

	for(unsigned i=0; i<hand.size(); i++)
	{
		suite[hand[i].getSuit()]++;
		face[hand[i].getFace()]++;
	}

	if(count(suite, suite+4, 5) == 1)
		return;

	if(count(suite, suite+4, 4) == 1)
	{
		index = find(suite, suite+4, 1);
		for(unsigned i=0; i<hand.size(); i++)
			if(hand[i].getSuit()==(index-suite))
			{
				hold[i] = false;
				return;
			}
	}

	index = find(face, face+13, 4);
	if((index-face)!=13)
	{
		holdFace(hand, hold, (index-face), false);
		return;
	}

	index = find(face, face+13, 3);
	if((index-face)!=13)
	{
		int *indexTemp = find(face, face+13, 2);
		if((indexTemp-face)!=13)
			return;

		holdFace(hand, hold, (index-face), false);
		return;
	}

	if(face[12] == 1 && count(face, face+4, 1) == 4)
		return;

	for(int i=0; i<9; i++)
		if(count(face+i, face+i+5, 1) == 5)
			return;

	if(face[12] == 1)
	{
		if(count(face, face+4, 2) == 1 && count(face, face+4, 1) == 2)
		{
			index = find(face, face+4, 2);
			holdFace(hand, hold, (index-face), true);
			return;
		}

		if(count(face, face+4, 1) == 3)
		{
			index = find(face+4, face+13, 1);
			holdFace(hand, hold, (index-face), true);
			return;
		}

	}

	for(int i=0; i<9; i++)
	{
		if(count(face+i, face+i+5, 0) == 1)
		{
			if(count(face+i, face+i+5, 2) == 1 && count(face+i, face+i+5, 1) == 3)
			{
				index = find(face+i, face+i+5, 2);
				if((index-face)<9)
				{
					holdFace(hand, hold, (index-face), true);
					return;
				}
				else
				{
					holdFace(hand, hold, (index-face), false);
					return;
				}
			}
		}

		if(count(face+i, face+i+5, 1) == 4)
		{
			index = find(face, face+i, 1);
			if(index != face+i)
			{
				holdFace(hand, hold, (index-face), true);
				return;
			}

			index = find(face+i+5, face+13, 1);
			holdFace(hand, hold, (index-face), true);
			return;
		}
	}

	if(count(face, face+13, 2) == 2)
	{
		index = find(face, face+13, 1);
		holdFace(hand, hold, (index-face), true);
		return;
	}

    if(count(face, face+13, 2) == 1)
	{
		index = find(face, face+13, 2);
		holdFace(hand, hold, (index-face), false);
		return;
	}

	for(unsigned i=0; i<hand.size(); i++)
		if(hand[i].getFace()<9)
			hold[i] = false;
}


int AutoHold::getScore(vector<Card> hand,int bet)
{
	fill(suite, suite+4, 0);
	fill(face, face+13, 0);
	for(unsigned i=0; i<hand.size(); i++)
	{
		suite[hand[i].getSuit()]++;
		face[hand[i].getFace()]++;
	}

	if(count(suite, suite+4, 5) == 1)
	{
		if(count(face+8, face+13, 1) == 5)
			return 250*bet;

		if(face[12] == 1 && count(face, face+4, 1) == 4)
			return 50*bet;
		for(int i=0; i<9; i++)
			if(count(face+i, face+i+5, 1) == 5)
				return 50*bet;
		return 6*bet;
	}

	if(face[12] == 1 && count(face, face+4, 1) == 4)
			return 4*bet;

	for(int i=0; i<9; i++)
		if(count(face+i, face+i+5, 1) == 5)
			return 4*bet;

	if(count(face, face+13, 4) == 1)
		return 25*bet;

	if(count(face, face+13, 3) == 1 && count(face, face+13, 2) == 1)
		return 9*bet;

	if(count(face, face+13, 3) == 1)
		return 3*bet;

	if(count(face, face+13, 2) == 2)
		return 2*bet;

    if(count(face, face+13, 2) == 1 && (find(face, face+13, 2)-face) > 8)
		return 1*bet;

	return 0;
}

AutoHold::~AutoHold() {
	// TODO Auto-generated destructor stub
}

