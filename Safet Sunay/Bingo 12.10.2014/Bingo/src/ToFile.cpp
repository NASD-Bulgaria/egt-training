/*
 * ToFile.cpp
 *
 *  Created on: 29.09.2014 ã.
 *      Author:
 */

#include "ToFile.h"

ToFile::ToFile()
{
	statsFromFile();
}

void ToFile::writeHsOutput(unsigned bonus)
{
	rec.credit = player1.getCredit();
	rec.countGames = player1.getGamesCount();
	rec.wins = player1.getWins();
	rec.bonus = bonus;


	rec.percent = ((float)rec.wins / (float)rec.countGames) * 100;
	ofstream file("Recovery.bin", ios::out|ios::binary);
	ofstream file2("Statistics.txt", ios::out);
	if ( !file )
	{
	  cerr << "File could not be opened" << endl;
	  exit( 1 );
	}
	if ( !file2 )
	{
	  cerr << "File could not be opened" << endl;
	  exit( 1 );
	}

	file.write( reinterpret_cast< const char * >(
	&rec ), sizeof( Recovery ) );


	file2 << setprecision(3) << rec.wins << setw(11) << rec.countGames <<setw(11)<< rec.percent;

	file.close();
	file2.close();
}

unsigned ToFile::readHsInput()
{
	ifstream file("Recovery.bin", ios::in|ios::binary);
	if ( !file )
	{
	  cerr << "File could not be opened" << endl;
	  exit( 1 );
	}
	ifstream file2("Statistics.txt", ios::in);
	if ( !file )
	{
	  cerr << "File could not be opened" << endl;
	  exit( 1 );
	}
	file.read( reinterpret_cast< char * >( &rec ),
	 sizeof( Recovery ) );

	player1.setCredit(rec.credit);
	player1.setGamesCount(rec.countGames);
	player1.setWins(rec.wins);

	file.close();
	file2.close();

	return rec.bonus;
}

void ToFile::statsFromFile()
{
	ifstream file2("Statistics.txt", ios::in);
	if ( !file2 )
	{
	  cerr << "File could not be opened" << endl;
	  exit( 1 );
	}
	getline(file2, statistics);
	file2.close();
}

ToFile::~ToFile()
{
}

string& ToFile::getStatistics()
{
	return statistics;
}

void ToFile::setStatistics(const string& statistics)
{
	this->statistics = statistics;
}
