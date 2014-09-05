//============================================================================
// Name        : AlphaBetAnimals.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	string animals[6] = { "PUMA","PARROT", "DOG", "CAT", "WHALE", "MONKEY"};
	int index = 0;
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(animals[j].compare(animals[j + 1]) > 0)
			{
				animals[j].swap(animals[j + 1]);
			}
		}
	}
	for(int i = 0; i < 6; i++)
	{
		cout << animals[i] << " ";
	}
	return 0;
}
