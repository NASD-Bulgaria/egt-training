/*
 * SavingsAccount.h
 *
 *  Created on: Aug 11, 2014
 *      Author: NandM
 */

#ifndef SAVINGSACCOUNT_H_
#define SAVINGSACCOUNT_H_
using namespace std;

class SavingsAccount {
public:
	static void modifyInterestRate(double);

	static double getInterestRate();

	SavingsAccount();

	SavingsAccount(double);

	double calculateMonthlyInterest();

	double getSavingsBallance() const;

	void setSavingsBallance(double);

	void printIfno();

	virtual ~SavingsAccount();

private:
	static double annualInterestRate;
	double savingsBallance;
};

#endif /* SAVINGSACCOUNT_H_ */
