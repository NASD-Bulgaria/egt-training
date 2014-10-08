#ifndef NUMBERS_H_
#define NUMBERS_H_

#include <bitset>
#include <set>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;


class Numbers
{
public:

	static const int SIZE = 81;

	Numbers(vector<int>);
	virtual ~Numbers();

	int getHits();
	void clearNumOfHit();
	vector<int> getNumbOfHit();
	void setRandomPicks();

	void printRandom();

	void clearReset();
	vector<int> getRandoms();
	bitset<SIZE> getRandomPicks();

private:

	bitset<SIZE> numbers;
	bitset<SIZE> randomPicks;
	vector<int> randoms;
	int hits;
	vector<int> numbOfHit;

};

#endif
