#ifndef BALANCE_H_
#define BALANCE_H_

class Balance
{
public:


	Balance(int);

	int getCredit() const;
	void calculateWin(int, int, const int[][11]);

	virtual ~Balance();
	void setCredit();
	void setFirstCredit(int);
	void setBet(int);
	int getBet();
private:

	int credit;
	int bet;

};

#endif
