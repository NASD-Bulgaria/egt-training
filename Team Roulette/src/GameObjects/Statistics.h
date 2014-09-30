#ifndef STATISTICS_H_
#define STATISTICS_H_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "EnumTypes.h"
using namespace GameObjects;
using namespace std;

class Statistics
{
public:
	Statistics(string path = "", int initialAmount = 0);
	bool write(short num, Color color, int totalBet, int winings, int currentBalance);
	const vector<vector<double> > read();
	virtual ~Statistics();
private:
	string path;
	const int initialAmount;
	fstream stream;
	bool initiateStream();
	double calcDeviateBet(int totalBet, int winings);
	double calcDeviateCapital(int currentBalance);
};

#endif /* STATISTICS_H_ */
