#include "Numbers.h"
#include <algorithm>

//vector<int> randoms;

Numbers::Numbers(vector<int> userSelects)
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




int Numbers::getHits() const
{
	int hits=0;
	for (int i = 0; i < SIZE; i++) {
		if (numbers.test(i) & randomPicks.test(i)) {
			hits++;
		}
	}

	return hits;
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

	for(unsigned int i = 0; i < randoms.size(); i++)
	{
		cout << randoms[i] << " ";
	}
}

void Numbers::printSelects()
{
	for (int i = 0; i<SIZE; i++)
	{
		if (numbers[i])
		{
			cout << i << " ";
		}
	}
	cout << endl;
}

void Numbers::clearReset()
{

		numbers.reset();
		randomPicks.reset();
		randoms.clear();

}

vector<int> Numbers::getRandoms()
{
	return randoms;
}

Numbers::~Numbers()
{
	// TODO Auto-generated destructor stub
}

