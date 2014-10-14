/*
 * Statistics.cpp
 *
 *  Created on: 19.09.2014
 *      Author: Kameliq
 */

#include "Statistics.h"

using namespace GameObjects;

Statistics::~Statistics() {
	lastTenNumbers->clear();
	delete lastTenNumbers;
	lastTenNumbers = NULL;
	lastTenPlayerRecords->clear();
	delete lastTenPlayerRecords;
	lastTenPlayerRecords = NULL;
}

Statistics::Statistics(string rootDir, int initialAmount) :
		initialAmount(initialAmount) {
	this->rootDir = rootDir;
	subDirs[0] = rootDir + "/allNumbers.dat";
	subDirs[1] = rootDir + "/numberDistribution.dat";
	lastTenNumbers = new vector<StatisticRecord>();
	lastTenPlayerRecords = new vector<PlayerRecord>();
	read();
}

void Statistics::write(short num, Color color, int totalBet, int winings,
		int currentBalance) {
	PlayerRecord record(lastTenPlayerRecords->size(), num,
			color, totalBet, winings, calcDeviateBet(totalBet,winings),
			calcDeviateCapital(currentBalance));
	lastTenPlayerRecords->push_back(record);
	if (lastTenPlayerRecords->size() > 10) {
		lastTenPlayerRecords->erase(lastTenPlayerRecords->begin());
	}
	if (initiateStream(subDirs[0])) {
		stream.seekp(0, stream.end);
		StatisticRecord statRecord(record.num,record.color);
		stream.write(reinterpret_cast<const char*>(&statRecord), sizeof(StatisticRecord));
		stream.close();
	}
	if (initiateStream(subDirs[1])) {
		stream.seekg(num * sizeof(int));
		int oldCount;
		stream.read(reinterpret_cast<char *>(&oldCount), sizeof(int));
		stream.seekp(num * sizeof(int));
		oldCount++;
		stream.write(reinterpret_cast<const char*>(&oldCount), sizeof(int));
		stream.close();
	}
}

void Statistics::read() {
	if (initiateStream(subDirs[0])) {
		StatisticRecord record;
		stream.seekg(0 , stream.end);
		lastTenNumbers->clear();
		while(lastTenNumbers->size() < 12 && stream.tellg() > 0){
			stream.seekg((int)stream.tellg() - sizeof(StatisticRecord));
			stream.read(reinterpret_cast<char *>(&record), sizeof(StatisticRecord));
			stream.seekg((int)stream.tellg() - sizeof(StatisticRecord));
			lastTenNumbers->push_back(record);
		}
		stream.close();
	}
	if (initiateStream(subDirs[1])) {
		int num;
		int counter = 0;
		while(stream.read(reinterpret_cast<char *>(&num), sizeof(int))){
			numberCount[counter] = num;
			counter++;
		}
		stream.close();
	}
}

bool Statistics::initiateStream(string subDir) {
	if (!stream.is_open()) {
		stream.open(subDir.data(), ios::in | ios::out | ios::binary);
	}
	if (!stream) {
		return false;
	}
	return true;
}

double Statistics::calcDeviateBet(int totalBet, int winings) {
	return winings / (double) totalBet * 100 - 100;
}

double Statistics::calcDeviateCapital(int currentBalance) {
	return (currentBalance / double(initialAmount) * 100) - 100;
}

int Statistics::numberCount[37] = {0};
