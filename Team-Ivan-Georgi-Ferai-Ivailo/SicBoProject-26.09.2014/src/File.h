/*
 * File.h
 *
 *  Created on: 23.09.2014 ã.
 *      Author: D00M
 */

#ifndef FILE_H_
#define FILE_H_

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


class File : public Player{
public:
	File();
	virtual ~File();
	void recordHighScore(int);
	void recordCredit(int);
	int recovery();
};

#endif /* FILE_H_ */
