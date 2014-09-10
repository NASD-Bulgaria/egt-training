//============================================================================
// Name        : Zadacha_2_STL_FILE.cpp
// Author      : Martin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
	ifstream inFile("matrix.txt",ios::in);
	if(!inFile)
	{
		exit(1);
	}
	int number;
	string arrInFile;
	vector<int> theMatrix;
	while(inFile>>arrInFile) //insert word by word

	{
		number = atoi(arrInFile.c_str());
		theMatrix.push_back(number);
	}

	int size = sqrt(theMatrix.size());
int	array[size][size];
int r = 0;
	for(int i = 0;i < size;i++)
	{
		for(int g = 0;g < size;g++)
		{
			array[i][g] = theMatrix[r];
			r++;
			cout<<array[i][g]<<" ";
		}
		cout<<endl;
	}
	for(int i = 0;i< size;i++)
	{
		int row = i ;
		for(int g = 0;g < size;g++)
		{
			 if(row >= 0)
			 {
				 cout<<array[row][g]<<" ";
				 row--;

			 }

		}
		cout<<endl;
	}
		for(int g = 1;g < size;g++)
		{
			int col = g;
			int row = size -1;
			while(col < size)
			{
			cout<<array[row][col]<<" ";
			col++;
			row--;
			}
			cout<<endl;
		}
	return 0;
}
