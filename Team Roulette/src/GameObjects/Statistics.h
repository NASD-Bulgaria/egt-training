#ifndef STATISTICS_H_
#define STATISTICS_H_

#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "EnumTypes.h"
#include "IRendable.h"
#include <iomanip>

using namespace GameObjects;
using namespace std;

struct PlayerRecord{
	PlayerRecord(int index = 0, short num = 0, Color color = NoneColor, int totalBet = 0,
			int winnings = 0, double deviateBet = 0,double deviateCapital = 0){
		this->num = num;
		this->color = color;
		this->totalBet = totalBet;
		this->winnings = winnings;
		this->deviateBet = deviateBet;
		this->deviateCapital = deviateCapital;
		this->index = index;
	}

	int index;
	short num;
	Color color;
	int totalBet;
	int winnings;
	double deviateBet;
	double deviateCapital;
};

struct StatisticRecord{
	StatisticRecord(short num = 0, Color color = NoneColor){
		this->num = num;
		this->color = color;
	}
	short num;
	Color color;
};

class Statistics
{
public:
	Statistics(string rootDir = "", int initialAmount = 0);
	void write(short num, Color color, int totalBet, int winings, int currentBalance);
	void read();
	virtual ~Statistics();

//private:
	string rootDir;
	string subDirs[2];
	fstream stream;
	vector<StatisticRecord>* lastTenNumbers;
	vector<PlayerRecord>* lastTenPlayerRecords;
	double calcDeviateBet(int totalBet, int winings);
	double calcDeviateCapital(int currentBalance);
	bool initiateStream(string subDir);
	const int initialAmount;
	static int numberCount [37];
};

#endif /* STATISTICS_H_ */
