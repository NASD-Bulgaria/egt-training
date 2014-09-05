#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include "Tool.h"
using namespace std;

void initializeFile( fstream & );
void inputData( fstream & );
void listTools( fstream & );
void updateRecord( fstream & );
void insertRecord( fstream & );
void deleteRecord( fstream & );
int instructions( void );

int main()
{
	int choice;
	char response;

	fstream file("hardware.dat", ios::in | ios::out);

	void (*f[])(fstream &) ={listTools, updateRecord, insertRecord, deleteRecord};


	if ( !file )
	{
		cerr << "File could not be opened.\n";
		exit( 1 );
	}

	// ask user if new file should be made
	cout << "Should the file be initialized (Y or N): ";
	cin >> response;
	response = toupper( response );


	while ( ( response != 'Y' ) && ( response != 'N' ) )
	{
		cout << "Invalid response. Enter Y or N: ";
		cin >> response;
		response = toupper( response );
	}

	if ( response == 'Y' )
	{
		initializeFile( file );
		inputData( file );
	} // end if

	while ( ( choice = instructions() ) != 5 )
	{
		( *f[ choice - 1 ] )( file );
		file.clear();
	}

	return 0;
}

void initializeFile(fstream &fRef)
{
	Tool blankItem;

	for(int i = 0; i < 100; i++)
	{
		fRef.write(reinterpret_cast<char *> (&blankItem), sizeof(Tool));
	}
}

void inputData(fstream &fRef)
{
	Tool temp;

	int number;
	string name;
	double price;
	int stock;


	cout << "Enter the part number (0 - 99, -1 to end input): ";
	cin >> number;

	while(number != -1)
	{
		cout << "Enter the tool name: ";
		cin.ignore();
		getline(cin, name);
		temp.setToolName(name);
		temp.setPartNumber(number);

		cout << "Enter quantity and price: ";
		cin >> stock >> price;
		temp.setInStock(stock);
		temp.setUnitPrice(price);

		fRef.seekp(temp.getPartNumber() * sizeof(Tool));


		fRef.write( reinterpret_cast< char * >( &temp ), sizeof( Tool ));

		cout << "Enter the part number (0-99, -1 to end input): ";
		cin >> number;
	}
}

int instructions()
{
	int choice;

	cout << "\nEnter a choice:\n1 List all tools."
		<< "\n2 Update record.\n3 Insert record."
		<< "\n4 Delete record.\n5 End program.\n";

	do
	{
		cout << "? ";
		cin >> choice;
	}
	while(choice < 1 || choice > 5);

	return choice;
}

void listTools(fstream &fRef)
{
	Tool temp;

	cout << setw(7) << "Record#" << "  " << left
		<< setw(30) << "Tool name" << left
		<< setw(13) << "Quantity" << left << setw(10) << "  Cost" << endl;


	for(int count = 0; count < 100 && !fRef.eof(); count++)
	{

		fRef.seekg(count * sizeof(Tool));
		fRef.read(reinterpret_cast<char *>(&temp), sizeof(Tool));


		if(temp.getPartNumber() >= 0 && temp.getPartNumber() < 100)
		{
			cout << fixed << showpoint;
			cout << left << setw(10) << temp.getPartNumber() << " "
				<< left << setw(30) << temp.getToolName() << left
				<< setw(13) << temp.getInStock() << setprecision(2)
				<< left << setw( 10 ) << temp.getUnitPrice() << '\n';
		}
	}
}

void updateRecord(fstream &fRef)
{
	Tool temp;
	int part;
	string name;
	int stock;
	double price;


    cout << "Enter the part number for update: ";
    cin >> part;


    fRef.seekg( part * sizeof( Tool ));
    fRef.read( reinterpret_cast< char * >( &temp ), sizeof( Tool ));

   if ( temp.getPartNumber() != -1 )
   {
	  cout << setw( 7 ) << "Record#" << "    " << left
		 << setw( 30 ) << "Tool name" << left
		 << setw( 13 ) << "Quantity" << left << setw( 15 ) << "Cost" << endl;

	  cout << fixed << showpoint;
	  cout << setw( 10 ) << temp.getPartNumber() << "    "
		 << left << setw( 30 ) << temp.getToolName()
		 << left << setw( 13 ) << temp.getInStock()
		 << setprecision( 2 ) << setw( 7) << temp.getUnitPrice() << '\n'
		 << "Enter the tool name: ";

	  cin.ignore();
	  getline( cin, name );
	  temp.setToolName( name );

	  cout << "Enter quantity and price: ";
	  cin >> stock >> price;
	  temp.setInStock( stock );
	  temp.setUnitPrice( price );

	  fRef.seekp( temp.getPartNumber() * sizeof( Tool ) );
	  fRef.write( reinterpret_cast< char * > ( &temp ), sizeof( Tool ) );
   }
   else
   {
	   cerr << "Cannot update. The record is empty.\n";
   }

}

void insertRecord( fstream &fRef )
{
   Tool temp;
   int part;
   string name;
   int stock;
   double price;

   cout << "Enter the part number for insertion: ";
   cin >> part;

   fRef.seekg( part * sizeof( Tool ) );
   fRef.read( reinterpret_cast< char * > ( &temp ), sizeof( Tool ) );

   if ( temp.getPartNumber() == -1 )
   {
      temp.setPartNumber( part );
      cout << "Enter the tool name: ";
      cin.ignore();
      getline( cin, name );
      temp.setToolName( name );

      cout << "Enter quantity and price: ";
      cin >> stock >> price;
      temp.setInStock( stock );
      temp.setUnitPrice( price );

      fRef.seekp( temp.getPartNumber() * sizeof( Tool ) );
      fRef.write( reinterpret_cast< char * >( &temp ), sizeof( Tool ) );
   }
   else
   {
	   cerr << "Cannot insert. The record contains information.\n";
   }

}

void deleteRecord( fstream &fRef )
{
   Tool blankItem;
   Tool temp;
   int part;

   cout << "Enter the part number for deletion: ";
   cin >> part;


   fRef.seekg( part * sizeof( Tool ) );
   fRef.read( reinterpret_cast< char * >( &temp ), sizeof( Tool ) );


   if ( temp.getPartNumber() != -1 )
   {
      fRef.seekp( part * sizeof( Tool ) );
      fRef.write(
         reinterpret_cast< char * >( &blankItem ), sizeof( Tool ) );
      cout << "Record deleted.\n";
   }
   else
      cerr << "Cannot delete. The record is empty.\n";
}








