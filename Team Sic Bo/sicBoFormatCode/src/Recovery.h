/*
 * Recovery.h
 *
 *  Created on: 3.10.2014 ã.
 *      Author: PC
 */

#ifndef RECOVERY_H_
#define RECOVERY_H_
#include <iostream>
#include<cstdlib>
using namespace std;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <string>
using std::string;

#include <fstream>
using std::ofstream;
using std::istream;

#include"Player.h"

class Recovery: public Player
{
protected:
	Player player;
public:
	Recovery();
	virtual ~Recovery();

	int highScore();
	void recordHighScore(int);
	void recordCredit(int);
	int recoveryCredits();
	int checkHighScore();
};

#endif /* RECOVERY_H_ */
