/*
 * Recovery.cpp
 *
 *  Created on: 3.10.2014 ã.
 *      Author: PC
 */

#include "Recovery.h"

Recovery::Recovery() {}

Recovery::~Recovery() {}
void Recovery::recordHighScore(int currScore)
{

	string score = "";

	ifstream readHighScore;
	readHighScore.open("resources//recovery//highscore.txt", ios::in);

	if(!readHighScore) {

		cerr <<"Recovery could not be opened!\n";
		exit(1);

	}

	readHighScore.clear();
	readHighScore.seekg(0);

	while(!readHighScore.eof()) {
		getline(readHighScore, score);
	}

	readHighScore.close();

	int maxWin = atoi(score.c_str());


	if(currScore > maxWin) {

		ofstream writeHighScore;
		writeHighScore.open("resources//recovery//highscore.txt", ios::out);

		if(!writeHighScore) {

			cerr <<"Recovery could not be opened!\n";
			exit(1);

		}
		writeHighScore << currScore;
		writeHighScore.close();
	}
}

int Recovery::recoveryCredits() {
	string credit = "";

	ifstream checkCredit;
	checkCredit.open("resources//recovery//credit.txt", ios::in);


	if(!checkCredit) {
		cerr <<"Recovery could not be opened!\n";
		exit(1);
     }
	checkCredit.clear();
	checkCredit.seekg(0);

	while(!checkCredit.eof()) {
		getline(checkCredit, credit);
	}
	checkCredit.close();

		int currCredit = atoi(credit.c_str());
		return currCredit;
}

void Recovery::recordCredit(int cred)
{
				ofstream writeCredit;
				writeCredit.open("resources//recovery//credit.txt", ios::out);

				if(!writeCredit) {

					cerr <<"Recovery could not be opened!\n";
					exit(1);

				}
				writeCredit << cred;
				writeCredit.close();
}

int Recovery::highScore() {
	string score = "";

	ifstream readHighScore;
	readHighScore.open("resources//recovery//highscore.txt", ios::in);

	if(!readHighScore) {

		cerr <<"Recovery could not be opened!\n";
		exit(1);

	}

	readHighScore.clear();
	readHighScore.seekg(0);

	while(!readHighScore.eof()) {
		getline(readHighScore, score);
	}

	readHighScore.close();

	int maxWin = atoi(score.c_str());
	return maxWin;
}

int Recovery::checkHighScore() {
	int high = 0;
	if(player.getWin() > highScore()){
		high = player.getWin();
	}
	return high;
}
