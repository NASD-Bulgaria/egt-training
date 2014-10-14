#include "CheckForBingo.h"

CheckForBingo::CheckForBingo()
{
	init();
}

void CheckForBingo::init()
{
	horizontal.clear();
	vertical.clear();
	diagonal.clear();

	// initialize the maps with keys(row, column) and value(matching numbers from ticket - 0 by default)
	for (int i = 0; i < 5; ++i)
	{
		if(i == 2) // initializes their value by 1 because they cross the free space
		{
			horizontal.insert(make_pair(i, 1));
			vertical.insert(make_pair(i, 1));
		}
		else
		{
			horizontal.insert(make_pair(i, 0));
			vertical.insert(make_pair(i, 0));
		}
	}

	// initialize the maps with keys(row, column) and value(matching numbers from ticket - 0 by default)
	// 0 - main diagonal
	// 1 - minor diagonal
	diagonal.insert(make_pair(0, 0));
	diagonal.insert(make_pair(1, 0));

	temp.row = -1;
	temp.col = -1;

	num = 0;
}

CheckForBingo::~CheckForBingo()
{
}

void CheckForBingo::setCol(int c)
{
	temp.col = c;
}

void CheckForBingo::setRow(int r)
{
	temp.row = r;
}

int CheckForBingo::getCol() const
{
	return temp.col;
}

int CheckForBingo::getRow() const
{
	return temp.row;
}

bool CheckForBingo::horizontalLine()
{
	map<int, int>::iterator it;

//	cout << "horizontal  " <<getRow()<<"  "<<getCol()<<endl;

	if(temp.row == -1)
	{
		return false;
	}

	it = horizontal.find(temp.row); // finds key(row)
	++(*it).second; // increase the value if there is a match

//	cout << "horizontal   " <<(*it).second<<endl;

	return (*it).second == 5; // if value == 5, BINGO !
}

bool CheckForBingo::verticalLine()
{
	if(temp.col == -1)
	{
		return false;
	}

	map<int, int>::iterator it = vertical.find(temp.col); // finds key(column)

//	assert(it != vertical.end());

	++(*it).second; // increase the value if there is a match

	return (*it).second == 5; // if value == 5, BINGO !
}

bool CheckForBingo::diagonalLine()
{
	if(temp.row == -1 || temp.col == -1)
	{
		return false;
	}

	map<int, int>::iterator it;

	if(temp.row == temp.col) // check if they are positioned at main diagonal
	{
		it = diagonal.find(0); // refers to main diagonal
		++(*it).second; // increase the value if there is a match

//		cout << "diagonal  " <<(*it).second<<endl;

		return (*it).second == 4; // if value == 4, BINGO !(4 because both cross the free space)
	}
	else if(temp.row + temp.col == 4) // check if they are positioned at minor diagonal(row + column = length - 1)
	{
		it = diagonal.find(1); // refers to minor diagonal
		++(*it).second; // increases the value if there is a match

//		cout << "diagonal  " <<(*it).second<<endl;

		return (*it).second == 4; // if value == 4, BINGO !(4 because both cross the free space)
	}

	return false;
}

RowAndCol CheckForBingo::ticketCheck(int num, string ticket[][5]) // check if drawn number is in the ticket
{
	// store row and column of the number(if exist) from the ticked
	RowAndCol result;

	string number;

	// change from integer to string
	stringstream inpNum;

	inpNum << num;

	number = inpNum.str();

	// ticket column
	int fCol;

	// check only the column with the correct range of numbers
	// (e.g. 44 / 15 = 2(column) (column 2 range - 31 to 45))
	if(num <= 15)
	{
		fCol = 0;
	}
	else if (num <= 30)
	{
		fCol = 1;
	}
	else if (num <= 45)
	{
		fCol = 2;
	}
	else if (num <= 60)
	{
		fCol = 3;
	}
	else
	{
		fCol = 4;
	}

//	for (int i = 0; i < 5; ++i)
//	{
//		for (int j = 0; j < 5; ++j)
//		{
//			cout<<ticket[i][j]<<" ";
//		}
//		cout << endl;
//	}

	// check for match
	for(int i = 0; i < 5; ++i)
	{
		// if matches store the row and column of the matching number and return
		if(ticket[i][fCol] == number)
		{
			result.row = i;
			result.col = fCol;

			return result;
		}
		else // return -1 if there are no matches
		{
			result.row = -1;
			result.col = -1;
		}
	}

	return result;
}

void CheckForBingo::setRowCol(int num, string ticket[][5])
{
	temp = ticketCheck(num, ticket);
}
