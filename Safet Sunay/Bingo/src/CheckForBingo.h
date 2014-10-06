#ifndef CHECKFORBINGO_H_
#define CHECKFORBINGO_H_

#include "GlobalVariables.h"

struct RowAndCol
{
	int row;
	int col;
};

class CheckForBingo
{
public:
	CheckForBingo();
	virtual ~CheckForBingo();

	void init();
	bool horizontalLine(); // checks for bingo in horizontal line
	bool verticalLine(); // checks for bingo in vertical
	bool diagonalLine(); // checks for bingo in diagonal
	void setRowCol(int, string[][5]);
	int getCol() const;
	int getRow() const;
	void setCol(int);
	void setRow(int);

private:
	// stores key(row, column or both(for diagonal)) from ticket and
	// value(count of checked number from the ticket) if value == 5, BINGO !
	map<int, int> horizontal; // row
	map<int, int> vertical; // column
	map<int, int> diagonal; // diagonal

	RowAndCol ticketCheck(int, string [][5]);

	int num;

	RowAndCol temp;
};

#endif /* CHECKFORBINGO_H_ */
