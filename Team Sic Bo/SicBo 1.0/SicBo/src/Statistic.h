/*
 * Statistic.h
 *
 *  Created on: Oct 6, 2014
 *      Author: Admin
 */

#ifndef STATISTIC_H_
#define STATISTIC_H_
#include <SDL2/SDL.h>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <limits>
#include <list>
#include <iomanip>
using namespace std;
class Statistic {
public:
	Statistic();
	virtual ~Statistic();

	//Utility
	void isFileLoad(fstream &file);
	fstream& goToLine(fstream& file,int line);
	string takeWordByPosition(string,int);
	string intToString(int number);
	void addStatisticToList(string strLine);

	void setGameStatistic(int bet,int win,int firstDice,int secondDice,int thirdDice);

//	void openStatisticFile();
	void saveStatisticsToFile();

	void calculateMainStatistic();
	void fillListFromFile();

	void print();
	void readDataFromFile(string fullStatisticData[]);

private:
	string mainStatistic;
	int betMoneys;
	int winMoneys;
	int dices[3];
	list<string> statisticList;
};

#endif /* STATISTIC_H_ */
