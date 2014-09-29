

#ifndef PAYTABLE_H_
#define PAYTABLE_H_

#include <iostream>
#include <iomanip>
using namespace std;

class PayTable {
public:

	PayTable(int);
	virtual ~PayTable();
	int getN() const;
	void print();

private:
	int n;
};

#endif
