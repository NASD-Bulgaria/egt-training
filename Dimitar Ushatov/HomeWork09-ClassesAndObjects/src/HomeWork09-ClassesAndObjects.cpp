//============================================================================
// Name        : HomeWork09-ClassesAndObjects.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Account.h"
#include "Invoice.h"
#include "Employee.h"
#include "Month.h"
#include "Date.h"
#include "Student.h"
using namespace std;

void testAccount() {
	Account a(1500);
	Account b(2000);
	cout << a.getBalance() << endl;
	cout << b.getBalance() << endl;
	a.setBalance(-200);
	b.credit(150);
	cout << a.getBalance() << endl;
	cout << b.getBalance() << endl;
	a.credit(1700);
	a.debit(1800);
	b.debit(1700);
	cout << a.getBalance() << endl;
	cout << b.getBalance() << endl;
	cout << 1 << endl;
}

void testInvoice() {
	Invoice a(111222, "Laptop Acer", 15, 870);
	cout << "Part Number: " << a.getPartNumber() << endl;
	cout << "Part Descrition: " << a.getPartDescrition() << endl;
	cout << "Sold Items Count: " << a.getItemsCount() << endl;
	cout << "Price Per Item: " << a.getItemPrice() << endl;
	cout << "Total Invoice Amount: " << a.getInvoiceAmount() << endl;
}

void testEmployee() {
	Employee dimitar("Dimitar", "Dimitrov", 570);
	Employee ivan("Ivan", "Ivanov", 860);
	Employee joro("Georgi", "Georgiev", 430);
	Employee employees[] = { dimitar, ivan, joro };

	cout << "Initial yearly salary of each employee is:" << endl;

	for (int emp = 0; emp < 3; ++emp) {
		cout << employees[emp].getFullName() << " yearly salary is "
				<< employees[emp].getYearlySalary() << endl;
	}

	for (int emp = 0; emp < 3; ++emp) {
		employees[emp].setSalary(employees[emp].getSalary() * 1.1);
	}

	cout << endl;
	cout << "After a 10% raise the yearly salary of each employee is as folows:"
			<< endl;

	for (int emp = 0; emp < 3; ++emp) {
		cout << employees[emp].getFullName() << " yearly salary is "
				<< employees[emp].getYearlySalary() << endl;
	}
}

void testDate() {
	Date date(28, December, 1992);
	date.displayDate();
}

int main() {
//	testAccount();
//	cout << endl;
//	testInvoice();
//	cout << endl;
//	testEmployee();
	testDate();
	return 0;
}
