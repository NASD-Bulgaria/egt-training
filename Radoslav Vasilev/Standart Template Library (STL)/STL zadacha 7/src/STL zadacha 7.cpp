//============================================================================
// Name        : STL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
using namespace std;

int main() {
	vector <int> numbers;
	 srand (time(NULL));
	for(int z = 0 ;z <10;z++)
	{
		numbers.push_back(-10+rand()%20);
		cout<<numbers[z]<<" " ;
	}

	for(size_t i = 0 ;i < numbers.size();i++)
	{
		if(numbers[i] <0 )
		{
			numbers.erase(numbers.begin()+i);
			i--;
		}

	}
	cout<< endl;
	for(size_t i = 0 ;i < numbers.size();i++)
		{
			cout<<numbers[i]<<" ";
		}
	return 0;
}
