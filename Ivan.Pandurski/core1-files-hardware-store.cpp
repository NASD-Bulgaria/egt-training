//============================================================================
// Name        : core1-files-hardware-store.cpp
// Author      : Ivan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
#include<iomanip>
#include<cstring>
#include<fstream>
#include<cstdlib>
#include"ClientsData.h"
using namespace std;
void outputLine(ostream&, ClientsData &);
int getAccount(char *);
void updateRecord(fstream&);
void deleteRecord( fstream& );
void outputLine( ostream&, ClientsData & );

int main() {

	ofstream outHardware("hardware.dat", ios::binary);
	if (!outHardware) {
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	ClientsData storeClient;
	for (int i = 0; i < 100; i++)
		outHardware.write(reinterpret_cast<const char *>(&storeClient),
				sizeof(storeClient));
	int number;
	char toolName[15];
	int toolNumber;
	double toolPrice;
	fstream outHardware1("hardware.dat", ios::in | ios::out | ios::binary);
	if (!outHardware1) {
		cerr << "File could not be opened." << endl;
		exit(1);
	} // end if

	cout << "Enter account number (1 to 100, 0 to end input)\n? ";

	// require user to specify account number
	ClientsData client;
	cin >> number;
	while (number > 0 && number <= 100) {
		// user enters last name, first name and balance
		cout << "Enter tool name, how many of this tool, price of tool\n? ";
		cin >> setw(15) >> toolName;
		cin >> setw(10) >> toolNumber;
		cin >> toolPrice;

		// set record accountNumber, lastName, firstName and balance values
		client.setNumber(number);
		client.setToolName(toolName);
		client.setToolNumber(toolNumber);
		client.setToolPrice(toolPrice);
		outHardware1.seekp((client.getNumber() - 1) * sizeof(ClientsData));

		// write user-specified information in file
		outHardware1.write(reinterpret_cast<const char *>(&client),
				sizeof(ClientsData));

		// enable user to enter another account
		cout << "Enter account number\n? ";
		cin >> number;
	}
	ifstream inHardware("hardware.dat", ios::in);
	if (!inHardware) {
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	cout << left << setw(10) << "Number" << setw(16) << "Name of tool"
			<< setw(11) << "Number of tools" << left << setw(10) << right
			<< "Price" << endl;
	ClientsData client1;
	inHardware.read(reinterpret_cast<char *>(&client1), sizeof(ClientsData));
	while (!inHardware.eof()) {
		// display record
		if (client1.getNumber() != 0)
			outputLine(cout, client1);
		inHardware.read(reinterpret_cast<char *>(&client1),
				sizeof(ClientsData));
	}
	fstream InOutHardware("hardware.dat", ios::in | ios::out);
	updateRecord(InOutHardware);
	deleteRecord( InOutHardware );
	return 0;
}

void outputLine(ostream &output, ClientsData &record) {
	output << left << setw(10) << record.getNumber() << setw(16)
			<< record.getToolName() << setw(11) << record.getToolNumber()
			<< setw(10) << setprecision(2) << right << record.getToolPrice()
			<< right << endl;
}

int getAccount(char * prompt) {
	int number;
	// obtain account-number value
	do {
		cout << prompt << " (1 - 100): ";
		cin >> number;
	} while (number < 1 || number > 100);

	return number;
}

void updateRecord(fstream &updateFile) {
// obtain number of account to update
	int number = getAccount("Enter account to update");
	updateFile.seekg((number - 1) * sizeof(ClientsData));

	// read first record from file
	ClientsData client;
	updateFile.read(reinterpret_cast<char *>(&client), sizeof(ClientsData));

	// update record
	if (client.getNumber() != 0) {
		outputLine(cout, client); // display the record

		// request user to specify transaction
		cout << "\nEnter how many tools u want to update: ";
		double tool; // charge or payment
		cin >> tool;

		// update record balance
		double oldToolNumber = client.getToolNumber();
		client.setToolNumber(oldToolNumber + tool);
		outputLine(cout, client); // display the record

		// move file-position pointer to correct record in file
		updateFile.seekp((number - 1) * sizeof(ClientsData));
		updateFile.write(reinterpret_cast<const char *>(&client),
				sizeof(ClientsData));
	} // end if
	else
		// display error if account does not exist
		cerr << "Tool #" << number << " has no information." << endl;
}

void deleteRecord( fstream &deleteFromFile )
{
 // obtain number of account to delete
 int number = getAccount( "Enter account to delete" );
 deleteFromFile.seekg( ( number - 1 ) * sizeof( ClientsData ) );

  // read record from file
  ClientsData client;
  deleteFromFile.read( reinterpret_cast< char * >( &client ),
  sizeof( ClientsData ) );

  // delete record, if record exists in file
  if ( client.getNumber() != 0 )
  {
  ClientsData toolClient; // create blank record

  // move file-position pointer to correct record in file
  deleteFromFile.seekp( ( number - 1 ) *
  sizeof( ClientsData ) );

  // replace existing record with blank recordu
 deleteFromFile.write(
  reinterpret_cast< const char * >( &toolClient ),
  sizeof( ClientsData ) );

  cout << "Account #" << number << " deleted.\n";
  } // end if
  else // display error if record does not exist
  cerr << "Account #" << number << " is empty.\n";
  }


