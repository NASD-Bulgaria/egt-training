#include "PayTable.h"

PayTable::PayTable(int numb)
{
	this->n=numb;

}

PayTable::~PayTable() {
	// TODO Auto-generated destructor stub
}

int PayTable::getN()const
{
	return n;
}

void PayTable::print()
{
	switch (getN()) {
	case 2:
		cout << setw(4) << right << "Hits" << setw(8) << right << "Payout" << endl;
		cout << setw(4) << right << 2 << setw(8) << right << 9 << endl;
		cout << setw(4) << right << 1 << setw(8) << right << 1 << endl;
		break;
	case 3:
		cout << setw(4) << right << "Hits" << setw(8) << right << "Payout" << endl;
		cout << setw(4) << right << 3 << setw(8) << right << 16 << endl;
		cout << setw(4) << right << 2 << setw(8) << right << 2 << endl;
		cout << setw(4) << right << 1 << setw(8) << right << 1 << endl;
		break;
	case 4:
		cout << setw(4) << right << "Hits" << setw(8) << right << "Payout" << endl;
		cout << setw(4) << right << 4 << setw(8) << right << 12 << endl;
		cout << setw(4) << right << 3 << setw(8) << right << 6 << endl;
		cout << setw(4) << right << 2 << setw(8) << right << 2 << endl;
		cout << setw(4) << right << 1 << setw(8) << right << "-" << endl;
		break;
	case 5:
		cout << setw(4) << right << "Hits" << setw(8) << right << "Payout" << endl;
		cout << setw(4) << right << 5 << setw(8) << right << 50 << endl;
		cout << setw(4) << right << 4 << setw(8) << right << 15 << endl;
		cout << setw(4) << right << 3 << setw(8) << right << 3 << endl;
		cout << setw(4) << right << 2 << setw(8) << right << 1 << endl;
		cout << setw(4) << right << 1 << setw(8) << right << "-" << endl;
		break;
	case 6:
		cout << setw(4) << right << "Hits" << setw(8) << right << "Payout" << endl;
		cout << setw(4) << right << 6 << setw(8) << right << 75 << endl;
		cout << setw(4) << right << 5 << setw(8) << right << 30 << endl;
		cout << setw(4) << right << 4 << setw(8) << right << 3 << endl;
		cout << setw(4) << right << 3 << setw(8) << right << 2 << endl;
		cout << setw(4) << right << 2 << setw(8) << right << 1 << endl;
		cout << setw(4) << right << 1 << setw(8) << right << "-" << endl;
		break;
	case 7:
		cout << setw(4) << right << "Hits" << setw(8) << right << "Payout" << endl;
		cout << setw(4) << right << 7 << setw(8) << right << 100 << endl;
		cout << setw(4) << right << 6 << setw(8) << right << 36 << endl;
		cout << setw(4) << right << 5 << setw(8) << right << 12 << endl;
		cout << setw(4) << right << 4 << setw(8) << right << 6 << endl;
		cout << setw(4) << right << 3 << setw(8) << right << 1 << endl;
		cout << setw(4) << right << 2 << setw(8) << right << "-" << endl;
		cout << setw(4) << right << 1 << setw(8) << right << "-" << endl;
		break;
	case 8:
		cout << setw(4) << right << "Hits" << setw(8) << right << "Payout" << endl;
		cout << setw(4) << right << 8 << setw(8) << right << 720 << endl;
		cout << setw(4) << right << 7 << setw(8) << right << 90 << endl;
		cout << setw(4) << right << 6 << setw(8) << right << 19 << endl;
		cout << setw(4) << right << 5 << setw(8) << right << 6 << endl;
		cout << setw(4) << right << 4 << setw(8) << right << 3 << endl;
		cout << setw(4) << right << 3 << setw(8) << right << 1 << endl;
		cout << setw(4) << right << 2 << setw(8) << right << "-" << endl;
		cout << setw(4) << right << 1 << setw(8) << right << "-" << endl;
		break;

	case 9:
		cout << setw(4) << right << "Hits" << setw(8) << right << "Payout" << endl;
		cout << setw(4) << right << 9 << setw(8) << right << 1200 << endl;
		cout << setw(4) << right << 8 << setw(8) << right << 80 << endl;
		cout << setw(4) << right << 7 << setw(8) << right << 20 << endl;
		cout << setw(4) << right << 6 << setw(8) << right << 8 << endl;
		cout << setw(4) << right << 5 << setw(8) << right << 4 << endl;
		cout << setw(4) << right << 4 << setw(8) << right << 2 << endl;
		cout << setw(4) << right << 3 << setw(8) << right << 1 << endl;
		cout << setw(4) << right << 2 << setw(8) << right << "-" << endl;
		cout << setw(4) << right << 1 << setw(8) << right << "-" << endl;
		break;
	case 10:
		cout << setw(4) << right << "Hits" << setw(8) << right << "Payout" << endl;
		cout << setw(4) << right << 10 << setw(8) << right << 1800 << endl;
		cout << setw(4) << right << 9 << setw(8) << right << 600 << endl;
		cout << setw(4) << right << 8 << setw(8) << right << 30 << endl;
		cout << setw(4) << right << 7 << setw(8) << right << 10 << endl;
		cout << setw(4) << right << 6 << setw(8) << right << 5 << endl;
		cout << setw(4) << right << 5 << setw(8) << right << 3 << endl;
		cout << setw(4) << right << 4 << setw(8) << right << 2 << endl;
		cout << setw(4) << right << 3 << setw(8) << right << 1 << endl;
		cout << setw(4) << right << 2 << setw(8) << right << "-" << endl;
		cout << setw(4) << right << 1 << setw(8) << right << "-" << endl;
		break;

	default:
		break;
	}
}
