//============================================================================
// Name        : File_4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{

		string newRow;
		int array[5][5];
		int max = 0;
		int count = 0;

		ifstream inFile("matrix.txt", ios::in);
		ofstream outFile("newMatrix.txt", ios::out);
		if (!inFile)
		{
			cerr<<"File (matrix.txt) could not be opened!"<<endl;
			exit( 1 );
		}

			if (!outFile)
			{
				cerr<<"File (newMatrix.txt) could not be opened!"<<endl;
				exit( 1 );
			}

			for (int i = 0; i < 5; ++i)
			{
				for (int j = 0; j < 5; ++j)
				{
					count++;
					inFile >> newRow;
					array[i][j] = atoi(newRow.c_str());
				}
			}

			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (max < array[i][j] + array[i][j+1] + array[i+1][j] + array[i+1][j+1])
					{
						max = array[i][j] + array[i][j+1] + array[i+1][j] + array[i+1][j+1];
					}
				}
			}


			outFile << sqrt(count) << endl;

			for (int i = 0; i < 5; ++i)
			{
				for (int j = 0; j < 5; ++j)
				{
					outFile << array[i][j] << " ";
				}
				outFile << endl;
			}
			outFile << max;






//			while(getline(inFile, newRow))
//			{
//				countRow++;
//				outFile<< countRow << " " << newRow << endl;
//				vectorSort.push_back(newRow);
//			}
//			sort(vectorSort.begin(), vectorSort.end());
//			for (size_t i = 0; i < vectorSort.size(); ++i)
//			{
//				cout<<vectorSort[i]<<endl;
//				outFile << vectorSort[i] << endl;
//
//			}



	return 0;
}
