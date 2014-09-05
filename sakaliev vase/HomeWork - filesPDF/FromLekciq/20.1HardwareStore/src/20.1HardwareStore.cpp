//============================================================================
// Name        : 1HardwareStore.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "Hardware.h"

using namespace std;

int enterChoice();
void createTextFile(fstream&);
void updateRecord(fstream&);
void newRecord(fstream&);
void deleteRecord(fstream&);
void outputLine(ostream&, const Hardware &);
int getAcount(const char* const);

enum Choices {
	PRINT = 1, UPDATE, NEW, DELETE, END
};

int main() {

	fstream inOutTools("hardware.dat", ios::in | ios::out);


	if (!inOutTools) {
		cerr << "The file coud not be opened !!!";
		exit(1);
	}
	int choice;

	while ((choice = enterChoice()) != END) {

		switch (choice) {
		case PRINT: // create text file from record file
			createTextFile(inOutTools);
			break;
		case UPDATE: // update record
			updateRecord(inOutTools);
			break;
		case NEW: // create record
			newRecord(inOutTools);
			break;
		case DELETE: // delete existing record
			deleteRecord(inOutTools);
			break;
		default: // display error if user does not select valid choice
			cerr << "Incorrect choice" << endl;
			break;

		}
		inOutTools.clear();

	}

	return 0;
}

int enterChoice() {

	cout << "\nEnter your choice" << endl << "1 -stored information about tools"
			<< endl << " in \"hardwareStore.txt\" " << endl
			<< "2 -update a tool" << endl << "3 -add a new tool" << endl
			<< "4 -delete a tool" << endl << "5 -end program\n? ";
	int menuChoice;
	cin >> menuChoice;
	return menuChoice;
}

void createTextFile(fstream& readFromFile) {
	ofstream outPrintFile("hardware.dat", ios::out);
	if (!outPrintFile) {
		cerr << "The file coud not be created !!!";
		exit(1);
	}

	outPrintFile << left << setw(15) << "Tools" << setw(6) << "Count"
			<< "Price(lv)\n";
	readFromFile.clear();
	readFromFile.seekg(0);

	Hardware tool;
	readFromFile.read(reinterpret_cast<char *>(&tool), sizeof(Hardware));

	while (!readFromFile.eof()) {
		if (tool.getAccountNumber() != 0) {
			outputLine(outPrintFile, tool);
		}
		readFromFile.read(reinterpret_cast<char*>(&tool), sizeof(Hardware));
	}
}

void updateRecord(fstream &updateFile) {
	int accountNumber = getAcount("Enter acount to update");
	updateFile.seekg((accountNumber) * sizeof(Hardware));

	Hardware tool;
	updateFile.read(reinterpret_cast<char *>(&tool), sizeof(Hardware));

	if (tool.getAccountNumber() != 0) {
		outputLine(cout, tool);

		cout << "Enter the description of tool: " << endl;
		string descript;
		getline(cin, descript);

		cout << "Enter the count: ";
		int count;
		cin >> count;

		cout << "Enter the price: ";
		double price;
		cin >> price;

		tool.setDescription(descript);
		tool.setCount(count);
		tool.setPrice(price);
		outputLine(cout, tool);

		updateFile.seekp((accountNumber) * sizeof(Hardware));
		updateFile.write(reinterpret_cast<const char*>(&tool),
				sizeof(Hardware));
		updateFile.clear();
		updateFile.seekg(0);
	} else {
		cerr << "There is no information yet !!!";
	}
}

void newRecord(fstream& insertInFile) {

	int accountNumber = getAcount("Enter new account nubmer");
	insertInFile.seekg(accountNumber * sizeof(Hardware));

	Hardware tool;
	tool.setAccountNumber(accountNumber);
	insertInFile.read(reinterpret_cast<char*>(&tool), sizeof(Hardware));

	if (tool.getAccountNumber() != 0) {
		string desrciption;
		int count;
		double price;

		cout << "Enter tool, count, price\n? ";
		cin >> desrciption;
		cin >> count;
		cin >> price;

		tool.setDescription(desrciption);
		tool.setCount(count);
		tool.setPrice(price);


		insertInFile.seekp(tool.getAccountNumber() * sizeof(Hardware));

		insertInFile.write(reinterpret_cast<const char *>(&tool),
				sizeof(Hardware));

	} else {
		cerr << "This line already contains information !!!";
	}

}

void deleteRecord(fstream& deleteFromFile) {

	int accountNumber = getAcount("Enter account to delete");

	deleteFromFile.seekg((accountNumber) * sizeof(Hardware));

	Hardware tool;
	deleteFromFile.read(reinterpret_cast<char *>(&tool), sizeof(Hardware));

	if (tool.getAccountNumber() != 0) {
		Hardware blankTool;

		deleteFromFile.seekp((accountNumber) * sizeof(Hardware));
		deleteFromFile.write(reinterpret_cast<const char *>(&blankTool),
				sizeof(Hardware));

		cout << "The line " << accountNumber << " deleted \n";
	} else {
		cerr << "The line " << accountNumber << " is empty\n";
	}
}

void outputLine(ostream &output, const Hardware &record) {

	output << left << setw(6) << record.getAccountNumber() << setw(16)
			<< record.getDescription() << setw(5) << record.getCount()
			<< setw(8) << record.getPrice() << " lv. \n";

}

int getAcount(const char * const prompt) {

	int accounNumber;
	do {
		cout << prompt << "(1-10): ";
		cin >> accounNumber;
	} while (accounNumber < 1 || accounNumber > 10);

	return accounNumber;
}

