/*
 * SavingsAccount.cpp
 *
 *  Created on: Aug 11, 2014
 *      Author: NandM
 */

#include "SavingsAccount.h"
#include <iostream>
using namespace std;

double SavingsAccount::annualInterestRate;

SavingsAccount::SavingsAccount() {
	this->savingsBallance = 0;
}

SavingsAccount::SavingsAccount(double savingsBallance) {
	this->savingsBallance = savingsBallance;
}


void SavingsAccount::modifyInterestRate(double annualInterestRate) {
	SavingsAccount::annualInterestRate = annualInterestRate;
}

double SavingsAccount::getInterestRate() {
	return annualInterestRate;
}

double SavingsAccount::calculateMonthlyInterest() {
	double interestValue = this->getSavingsBallance() * annualInterestRate / 1200;

	this->setSavingsBallance(this->getSavingsBallance() + interestValue);

	return interestValue;
}

double SavingsAccount::getSavingsBallance() const {
	return this->savingsBallance;
}

void SavingsAccount::setSavingsBallance(double savingsBallance) {
	this->savingsBallance = savingsBallance;
}

SavingsAccount::~SavingsAccount() {
	cout << "Deconstructor called" << endl;
}

void SavingsAccount::printIfno() {
	cout << string(5, ' ') << "Interest rate: " << SavingsAccount::getInterestRate()
			<< endl;
	cout << string(5, ' ') << "Savings ballance: "
			<< this->getSavingsBallance() << endl;
	cout << string(5, ' ') << "Interest value: "
			<< this->calculateMonthlyInterest() << endl;
	cout << string(5, ' ') << "Savings ballance after added interest value: "
			<< this->getSavingsBallance() << endl;
}
