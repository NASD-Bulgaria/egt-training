//============================================================================
// Name        : Lection8Ex6.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

const int N = 8;
int position[N];

bool isSafe(int queen_number, int row_position)
{

	for (int i = 0; i < queen_number; i++)
	{
		int other_row_pos = position[i];


		if (other_row_pos == row_position ||
			other_row_pos == row_position - (queen_number - i) ||
			other_row_pos == row_position + (queen_number - i))
			return false;
	}
	return true;
}
int solNumber = 0;
void solve(int k)
{
	if (k == N)
	{
		cout << "Solution: " << ++solNumber << " ";
		for (int i = 0; i < N; i++)
			cout << position[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (isSafe(k, i))
			{
				position[k] = i;
				solve(k + 1);
			}
		}
	}
}

int main()
{
	solve(0);

	return 0;
}
