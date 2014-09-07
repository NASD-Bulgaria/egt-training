//============================================================================
// Name        : zada4a.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#define n 5

using namespace std;

int main()
{

		int count= 0;
		int max=0;
		string newRow;
		int array[n][n];
		ifstream inFile("masiv.txt",ios::in);
		ofstream outFile("newASD",ios::out);


		if(!inFile)
		{
			cerr<<"File Cloud not be opened"<<endl;
			exit(1);
		}
		if(!outFile)
		{
			cerr<<"File (newASD.txt)could not be opened!"<<endl;
		}

		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j < n;j++)
			{
				count++;
				inFile>>newRow;
				array[i][j] = atoi(newRow.c_str());
			}
		}
		for(int i = 0; i<n-1;i++)
		{
			for(int j = 0 ; j < n-1;j++)
			{
				if(max < (array[i][j]+array[i][j+1]+array[i+1][j]+array[i+1][j+1]))
				{
					max = array[i][j]+array[i][j+1]+array[i+1][j]+array[i+1][j+1];
				}
			}
		}

		outFile<<sqrt(count)<<endl;
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j < n;j++)
			{
						outFile<<array[i][j]<<" ";
			}
			outFile<<endl;
		}

		outFile<<max;
	return 0;
}
