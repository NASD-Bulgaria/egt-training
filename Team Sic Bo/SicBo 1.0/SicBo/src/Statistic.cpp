/*
 * Statistic.cpp
 *
 *  Created on: Oct 6, 2014
 *      Author: Admin
 */

#include "Statistic.h"

Statistic::Statistic() : betMoneys(0),winMoneys(0){}

Statistic::~Statistic() {}//UTILITY
void Statistic::isFileLoad(fstream &file)
{
	if(!file)
	{
		cout << "Statistic file could not be opened !";
		exit ( 1 );
	}
}
fstream& Statistic::goToLine(fstream& file,int line)
{
	file.seekg(std::ios::beg);
	for(int i=0; i < line - 1; ++i){
		file.ignore(numeric_limits<std::streamsize>::max(),'\n');
	}
    return file;
}
string Statistic::intToString(int number)
{
	string text = static_cast<ostringstream*>(&(ostringstream() << number))->str();
	return text;
}
string Statistic::takeWordByPosition(string strLine,int position)
{
	int counter = 0;
	string word = "";
	for(size_t i = 0;i < strLine.size();++i)
	{
		if(strLine[i] != ' ')
		{
			word += strLine[i];
		}
		else
		{
			counter++;
			if(counter == position)
			{
				break;
			}
			word = "";
		}
	}
	return word;
}
void Statistic::addStatisticToList(string strLine)
{
	if(statisticList.size() < 15)
	{
		statisticList.push_back(strLine);
	}
	else
	{
		statisticList.front();
		statisticList.pop_front();
		statisticList.push_back(strLine);
	}
}

//Player statistic information
void Statistic::setGameStatistic(int bet,int win,int firstDice,int secondDice,int thirdDice)
{
	betMoneys = bet;
	winMoneys = win;
	dices[0] = firstDice;
	dices[1] = secondDice;
	dices[2] = thirdDice;

	string allInformation;
	allInformation += "Bet: " + intToString(betMoneys) + " | ";
	allInformation += "Win: " + intToString(winMoneys) + " |  ";
	allInformation += "Dices: " + intToString(dices[0]) + " - ";
	allInformation += intToString(dices[1]) + " - ";
	allInformation += intToString(dices[2]) + " ";

	addStatisticToList(allInformation);
}

//File operations
void Statistic::saveStatisticsToFile()
{
	fstream output("resources/recovery/Statistic.txt",ios::out);
	isFileLoad(output);

	output<<mainStatistic + "\n";

	list<string>::iterator it;
	int lengthList = statisticList.size();
	int i = 0;
	for(it = statisticList.begin();it!=statisticList.end();++it,++i)
	{
		if(i < lengthList - 1)
		{
			output <<(*it) + "\n";
		}
		else
		{
			output<<(*it);
		}

	}
	output.close();
}
void Statistic::calculateMainStatistic()
{
	int totalCurrentBet = 0;
	int totalCurrentWin = 0;

	list<string>::iterator it;
	for(it = statisticList.begin();it!=statisticList.end();++it)
	{
		 string bet = takeWordByPosition((*it),2);
		 string win = takeWordByPosition((*it),5);

		 totalCurrentBet += atoi(bet.c_str());
		 totalCurrentWin += atoi(win.c_str());
	}

	int avgBetPerGame = totalCurrentBet / statisticList.size();
	int avgWinPerGame = totalCurrentWin / statisticList.size();

	//Total bet, total win, average bet/game, average win/game.
	mainStatistic =  "Total Bet: " + intToString(totalCurrentBet) + " | ";
	mainStatistic += "Total Win: " + intToString(totalCurrentWin) + " | ";
	mainStatistic += "Average Bet: " + intToString(avgBetPerGame) + " | ";
	mainStatistic += "Average Win: " + intToString(avgWinPerGame) + " ";
}
void Statistic::fillListFromFile()
{
	fstream input("resources/recovery/Statistic.txt",ios::in);
	isFileLoad(input);
	goToLine(input,2);
	while(!input.eof())
	{
		string temp;
		getline(input,temp);
		addStatisticToList(temp);
	}
	input.close();
}

//Console operation
void Statistic::print()
{
	list<string>::iterator it;
	cout<< left <<setw(15)<<mainStatistic<<endl;
	for(it = statisticList.begin();it!=statisticList.end();++it)
	{
		cout<< (*it)<<endl;
	}
}

void Statistic::readDataFromFile(string fullStatisticData[])
{
	fstream input("resources/recovery/Statistic.txt",ios::in);
	isFileLoad(input);
	input.clear();
	input.seekg(0);
	int i = 0;
	while(!input.eof())
	{
		getline(input, fullStatisticData[i]);
		i++;
	}
	input.close();
}
