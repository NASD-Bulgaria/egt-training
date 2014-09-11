//============================================================================
// Name        : 11.cpp
// Author      : Martin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Name        : Labyrinth.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <map>
using namespace std;
/////////Çàäà÷àòà ðàáîòè êàòî öÿëî, èìà ìàëúê ïðîáëåì - àêî ñå ñëó÷è, òàêà ÷å ñòúïêàòà äà ñòàíå ïî-ãîëÿìà îò 9,
/////////ùå îòïå÷òà íÿêàêúâ äðóã char ñïîðåä êîäà ìó, à íÿìà äà îòïå÷àòà 10, 11 è òí.
int main() {

	int n;
	cout << "Enter size of the matrix: ";
	cin >> n;
	char matrix[n][n];
	char x = 'x';
	char star = '*';
	char zero = '0';
	char unreach = 'u';

	//fill with zeros
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			matrix[i][j] = zero;
		}
	}

	//put a star
	srand(time(0));
	int star1 = rand() % n;
	int star2 = rand() % n;
	matrix[star1][star2] = star;

	//put x
	for(int i = 0; i < n * 2; i++)
	{
		int pos1 = rand() % n;
		int pos2 = rand() % n;
		if((pos1 == star1) && (pos2 == star2))
		{
			continue;
		}
		else
		{
			matrix[pos1][pos2] = x;
		}
	}

	///check results so far
	for(int i = 0; i < n; i++)
	{
		cout << endl;
		for(int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
	}


	cout << endl;

	/////////put 1 next to star
	if((star1 - 1 > -1) && (matrix[star1 - 1][star2] != x))
	{
		matrix[star1 - 1][star2] = zero + 1;
	}
	if((star1 + 1 < n) && (matrix[star1 + 1][star2] != x))
	{
		matrix[star1 + 1][star2] = zero + 1;
	}
	if((star2 + 1 < n) && (matrix[star1][star2 + 1] != x))
	{
		matrix[star1][star2 + 1] = zero + 1;
	}
	if((star2 - 1 > -1) && (matrix[star1][star2 - 1] != x))
	{
		matrix[star1][star2 - 1] = zero + 1;
	}

	int iterations = n * n;
	//////Check rows down

	while(iterations != -1)
	{
		///////////Check rows down
		for(int row = 0; row < n - 1; row++)
		{
			for(int col = 0; col < n; col++)
			{
				if((matrix[row][col] != zero)
						&&(matrix[row][col] != star)
						&&(matrix[row][col] != x)
						&&(matrix[row + 1][col] == zero))
				{
					matrix[row + 1][col] = matrix[row][col] + 1;
				}
			}
		}

		///////////////check rows up

		for(int row = n - 1; row > 0; row--)
		{
			for(int col = 0; col < n; col++)
			{
				if((matrix[row][col] != zero)
						&&(matrix[row][col] != star)
						&&(matrix[row][col] != x)
						&&(matrix[row - 1][col] == zero))
				{
					matrix[row - 1][col] = matrix[row][col] + 1;
				}
			}
		}

		///////////////check cols left
		for(int row = 0; row < n; row++)
		{
			for(int col = 0; col < n - 1; col++)
			{
				if((matrix[row][col] != zero)
						&&(matrix[row][col] != star)
						&&(matrix[row][col] != x)
						&&(matrix[row][col + 1] == zero))
				{
					matrix[row][col + 1] = matrix[row][col] + 1;
				}
			}
		}
		///////Check cols right
		for(int row = 0; row < n; row++)
		{
			for(int col = n - 1; col > 0; col--)
			{
				if((matrix[row][col] != zero)
						&&(matrix[row][col] != star)
						&&(matrix[row][col] != x)
						&&(matrix[row][col - 1] == zero))
				{
					matrix[row][col - 1] = matrix[row][col] + 1;
				}
			}
		}
		iterations --;
	}
///////////////unreachables
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(matrix[i][j] == zero)
			{
				matrix[i][j] = unreach;
			}
		}
	}


	for(int i = 0; i < n; i++)
	{
		cout << endl;
		for(int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
	}

	return 0;
}
