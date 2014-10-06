/*
 * ToFile.h
 *
 *  Created on: 29.09.2014 ã.
 *      Author:
 */

#ifndef TOFILE_H_
#define TOFILE_H_

#include "GlobalVariables.h"
#include <iomanip>
struct Recovery
{
	int credit;
	int countGames;
	int wins;
	float percent;
};
class ToFile
{
public:
	ToFile();
	void writeHsOutput();
	void readHsInput();
	void statsFromFile();
	virtual ~ToFile();
	string& getStatistics();
	void setStatistics(const string& statistics);

private:
	Recovery rec;
	string statistics;
};

#endif /* TOFILE_H_ */
