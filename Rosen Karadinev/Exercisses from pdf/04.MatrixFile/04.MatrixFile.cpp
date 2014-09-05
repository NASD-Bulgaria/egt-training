#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	ifstream readMatrix("matrix.txt", ios::in);
	ofstream maxSum("maxSum.txt", ios::out);

	if(!readMatrix && !maxSum)
	{
		cerr << "The file could not be opened";
	}

	int size;
	int number;
	int count = 0;

	while(readMatrix >> number)
	{
		size = number;
		break;
	}


	int matrix[size][size];


	for(int i = 0; i < size; i++)
	{
		while(readMatrix >> number)
		{
			matrix[i][count] = number;
			count++;
		}
		count = 0;
	}

	cout << "The matrix is: " << endl;

	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}

	int bestSum = 0;
	int bestRow = 0;
	int bestCol = 0;

	for (int rows = 0; rows < size - 1; rows++)
		{
			for (int cols = 0; cols < size - 1; cols++)
			{
				int sum = matrix[rows][cols] + matrix[rows][cols + 1]
						+ matrix[rows + 1][cols] + matrix[rows + 1][cols + 1];
				if (sum > bestSum)
				{
					bestSum = sum;
					bestRow = rows;
					bestCol = cols;
				}
			}
		}

	cout << endl << "The best platform is:" << endl;
	cout <<  matrix[bestRow][bestCol] <<" "<< matrix[bestRow][bestCol + 1] << endl;
	cout <<  matrix[bestRow + 1][bestCol] <<" "<< matrix[bestRow + 1][bestCol + 1]  << endl;
	cout << "The maximal sum is: "<< bestSum;


	maxSum << "The max sum from submatrix 2x2 is " << bestSum;

	return 0;
}
