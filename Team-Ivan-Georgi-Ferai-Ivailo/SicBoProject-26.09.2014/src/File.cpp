/*
 * File.cpp
 *
 *  Created on: 23.09.2014 ã.
 *      Author: D00M
 */

#include "File.h"

File::File() {
}

File::~File() {

}

void File::recordHighScore(int currScore) {

	string score = "";

	ifstream readHighScore;
	readHighScore.open("highscore.txt", ios::in);

	if(!readHighScore) {

		cerr <<"File could not be opened!\n";
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
		writeHighScore.open("highscore.txt", ios::out);

		if(!writeHighScore) {

			cerr <<"File could not be opened!\n";
			exit(1);

		}
		writeHighScore << currScore;
		writeHighScore.close();
	}

}

int File::recovery() {
	string credit = "";

	ifstream checkCredit;
	checkCredit.open("credit.txt",ios::in);
	if(!checkCredit) {
		cerr <<"File could not be opened!\n";
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

void File::recordCredit(int cred)
{
				ofstream writeCredit;
				writeCredit.open("credit.txt", ios::out);

				if(!writeCredit) {

					cerr <<"File could not be opened!\n";
					exit(1);

				}
				writeCredit << cred;
				writeCredit.close();


}
