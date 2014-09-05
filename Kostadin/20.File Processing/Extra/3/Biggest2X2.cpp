//============================================================================
// Name        : Biggest2X2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ifstream inFile( "matrix.txt", ios::in );
	if(!inFile)
	{
		cerr<< "File could not be opened!"<<endl;
		exit(1);
	}
	ofstream endFile("biggest2x2.txt", ios::out);
	if(!endFile)
	{
		cerr<< "File could not be opened!"<<endl;
		exit(1);
	}

	string num;
	getline(inFile, num);
	int size = atoi(num.c_str());

	int arr[size][size];

	for(int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			inFile >> num;
			arr[i][j] = atoi(num.c_str());
		}
	}
	int max = arr[0][0] + arr[0][1] + arr[1][0] + arr[1][1];
	for(int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if(arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1] > max)
			{
				max = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1];
			}
		}
	}
	endFile << max << endl;
	return 0;
}
