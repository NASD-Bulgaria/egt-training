//============================================================================
// Name        : 1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string.h>
using namespace std;

#include "HardwareStore.h"

int enterChoice();
void createTextFile( fstream& );
void updateRecord( fstream& );
void newRecord( fstream& );
void deleteRecord( fstream& );
void outputLine( ostream&, const HardwareStore & );
int getNumber( const char * const );

enum Choice { PRINT = 1, UPDATE, NEW, DELETE, END };

int main() {

	fstream inOutStore("hardware.dat", ios::in | ios::out);
	if (!inOutStore) {
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	int choice;

	while ((choice = enterChoice()) != END) {
		switch (choice) {
		case PRINT:
			createTextFile(inOutStore);
			break;
		case UPDATE:
			updateRecord(inOutStore);
			break;
		case NEW:
			newRecord(inOutStore);
			break;
		case DELETE:
			deleteRecord(inOutStore);
			break;
		default:
			cerr << "Incorrect choice" << endl;
			break;
		}
		inOutStore.clear();
	}


	return 0;
}

int enterChoice()
{
cout  << "\nEnter your choice" << endl

			<< "1 - store a formatted text file of hardware list" << endl
			<< " called \"print.txt\" for printing" << endl
			<< "2 - update a tool" << endl << "3 - add a new tool"
			<< endl << "4 - delete a tool" << endl << "5 - end program\n? ";
	int menuChoice;
	cin >> menuChoice;
	return menuChoice;
}

void createTextFile( fstream &readFromFile )
{

	ofstream outPrintFile("print.txt", ios::out);
	if (!outPrintFile) {
		cerr << "File could not be created." << endl;
		exit(1);
	}
	outPrintFile << left << setw(10) << "Number" << setw(30) << "Tool"
			<< setw(10) << "Quantity" << right << setw(10) << "Price"
			<< endl;
	readFromFile.seekg(0);

	HardwareStore store;
	readFromFile.read(reinterpret_cast<char *>(&store), sizeof(HardwareStore));
	while (!readFromFile.eof()) {
		if (store.getIdNumber() != 0)
			outputLine(outPrintFile, store);
	readFromFile.read( reinterpret_cast< char * >( &store ),
			sizeof( HardwareStore ) );
		}
}

void updateRecord( fstream &updateFile )
{

	int idNumber = getNumber("Enter a tool to update");
	updateFile.seekg((idNumber - 1) * sizeof(HardwareStore));
	HardwareStore store;
	updateFile.read(reinterpret_cast<char *>(&store), sizeof(HardwareStore));
	if (store.getIdNumber() != 0) {
		outputLine(cout, store);
				cout << "\nEnter new quantity: ";
				int newquantity;
				cin >> newquantity;
				store.setQuantity(newquantity);
				outputLine(cout, store);

				updateFile.seekp((idNumber - 1) * sizeof(HardwareStore));
				updateFile.write(reinterpret_cast<const char *>(&store),
				sizeof(HardwareStore));


		outputLine(cout, store);
		cout << "\nEnter new price: ";
		double newprice;
		cin >> newprice;
		store.setPrice(newprice);
		outputLine(cout, store);

		updateFile.seekp((idNumber - 1) * sizeof(HardwareStore));
		updateFile.write(reinterpret_cast<const char *>(&store),
				sizeof(HardwareStore));
	}
	else

		cerr << "Tool #" << idNumber << " has no information." << endl;
}

void newRecord( fstream &insertInFile )
{
	int idNumber = getNumber("Enter new tool");

	insertInFile.seekg((idNumber - 1) * sizeof(HardwareStore));

	HardwareStore store;
	insertInFile.read(reinterpret_cast<char *>(&store), sizeof(HardwareStore));
	if (store.getIdNumber() == 0) {
		char name[30];
		int quantity;
		double price;
		cout << "Enter name, quantity, price\n? ";
		cin >> setw(30) >> name;
		cin >> setw(10) >> quantity;
		cin >> price;

		store.setName(name);
		store.setQuantity(quantity);
		store.setPrice(price);
		store.setIdNumber(idNumber);
		insertInFile.seekp((idNumber - 1) * sizeof(HardwareStore));
		insertInFile.write(reinterpret_cast<const char *>(&store),
				sizeof(HardwareStore));
	} else
		cerr << "Id number #" << idNumber << " already contains information."
				<< endl;
}

void deleteRecord( fstream &deleteFromFile )
{
	int idNumber = getNumber("Enter number to delete");
	deleteFromFile.seekg((idNumber - 1) * sizeof(HardwareStore));
	HardwareStore store;
	deleteFromFile.read(reinterpret_cast<char *>(&store),
			sizeof(HardwareStore));
	if (store.getIdNumber() != 0) {
		HardwareStore blankStore; // create blank record
		deleteFromFile.seekp((idNumber - 1) * sizeof(HardwareStore));
		deleteFromFile.write(reinterpret_cast<const char *>(&blankStore),
				sizeof(HardwareStore));

		cout << "Id number #" << idNumber << " deleted.\n";
	} else
		cerr << "Id number #" << idNumber << " is empty.\n";
}

void outputLine( ostream &output, const HardwareStore &record )
 {
	output << left << setw(10) << record.getIdNumber() << setw(30)
			<< record.getName() << setw(10) << record.getQuantity() << setw(10)
			<< setprecision(2) << right << fixed << showpoint
			<< record.getPrice() << endl;
}

int getNumber( const char * const prompt )
 {
	int idNumber;
	do {
		cout << prompt << " (1 - 100): ";
		cin >> idNumber;
	} while (idNumber < 1 || idNumber > 100);

	return idNumber;
}
