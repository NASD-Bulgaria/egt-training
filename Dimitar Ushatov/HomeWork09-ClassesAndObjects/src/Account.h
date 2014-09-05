/*
 * Account.h
 *
 *  Created on: Jul 22, 2014
 *      Author: NandM
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <iostream>
using namespace std;

class Account{
public:
	Account(int balance){
		this->setBalance(balance);
	}

	int getBalance() const {
		return this->balance;
	}

	void setBalance(int balance) {
		if (balance < 0) {
			cout<<"The balance must be positive or zero!"<<endl;
			this->balance = 0;
		} else {
			this->balance = balance;
		}
	}

	void credit(int amount){
		if (amount >= 0 ) {
			this->balance += amount;
		} else{
			cout << "The amount can't be less then zero!"<<endl;
		}
	}

	void debit(int amount){
		if (amount <= this->balance) {
			this->balance -= amount;
		} else {
			cout << "The amount exceeds the balance value!"<<endl;
		}
	}

private:
	int balance;
};

#endif /* ACCOUNT_H_ */
