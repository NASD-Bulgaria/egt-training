#include "Numbers.h"
#include <algorithm>

static const int SIZE = 81;
Numbers::Numbers(vector<int> &userSelects)
{
	for(unsigned int i = 0; i < userSelects.size(); i++)
	{
		this->numbers.set(userSelects[i]);
	}

	setRandomPicks();
}


void Numbers::setRandomPicks()
{
	while (randomPicks.count() < 20)
	{
		this->randomPicks.set(1 + rand() % 80);
	}
}


int Numbers::getHits()
{
	int hits=0;
	for (int i = 0; i < SIZE; i++) {
		if (numbers.test(i) & randomPicks.test(i)) {
			hits++;
			numbOfHit.push_back(i);
		}
	}

	return hits;
}

vector<int> Numbers::getNumbOfHit()
{
	return numbOfHit;
}

void Numbers::printRandom()
{
	for (int i = 0; i < SIZE; i++)
	{
		if (randomPicks[i])
		{
			randoms.push_back(i);
		}
	}

	random_shuffle(randoms.begin(), randoms.end() );
}


void Numbers::clearReset()
{

		numbers.reset();
		randomPicks.reset();
		randoms.clear();
}

void Numbers::clearNumOfHit() {
	numbOfHit.clear();
}

bitset<SIZE> Numbers::getRandomPicks(){
	return randomPicks;
}

vector<int> Numbers::getRandoms()
{
	return randoms;
}

Numbers::~Numbers(){
}

