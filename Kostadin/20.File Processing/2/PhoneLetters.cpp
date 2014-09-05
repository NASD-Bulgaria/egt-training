//============================================================================
// Name        : PhoneLetters.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
//	char key2[3] = {'a', 'b', 'c'};
//	char key3[3] = {'d', 'e', 'f'};
//	char key4[3] = {'g', 'h', 'i'};
//	char key5[3] = {'j', 'k', 'l'};
//	char key6[3] = {'m', 'n', 'o'};
//	char key7[4] = {'p', 'q', 'r', 's'};
//	char key8[3] = {'t', 'u', 'v'};
//	char key9[4] = {'w', 'x', 'y', 'z'};


	ofstream phoneLettersFile( "print.txt", ios::out );
	if(!phoneLettersFile)
	{
		cerr<<"File could not be opened!"<<endl;
		exit(1);
	}


	string keys[] = {"0", "0", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};



	long phoneNum;
	cout <<"Enter phone number (7-digit): ";
	cin>>phoneNum;

	phoneLettersFile <<phoneNum << endl;


	vector <int> phoN;
	int digit;
	long down = 1000000;

	long tmp = phoneNum;
	for(int i = 0; i < 7; i++)
	{
		digit = tmp/down;
		tmp = tmp % down;
		down = down / 10;
		phoN.push_back(digit);
	}


	string temp[7];
	for(int i = 0; i < phoN.size(); i++)
	{
		temp[i] = keys[phoN[i]];
	}
	int count = 0;
	for(int i = 0; i < temp[0].size(); i++)
	{
		for(int j = 0; j < temp[1].size(); j++)
		{
			for(int k = 0; k < temp[2].size(); k++)
			{
				for(int l = 0; l < temp[3].size(); l++)
				{
					for(int m = 0; m < temp[4].size(); m++)
					{
						for(int n = 0; n < temp[5].size(); n++)
						{
							for(int o = 0; o < temp[6].size(); o++)
							{
								count++;
								phoneLettersFile << temp[0][i]<< temp[1][j]<< temp[2][k]<< temp[3][l]<< temp[4][m]<< temp[5][n]<< temp[6][o]<<endl;
							}
						}
					}
				}
			}
		}
	}
	phoneLettersFile << count << endl;

	phoneLettersFile.close();
	return 0;
}
