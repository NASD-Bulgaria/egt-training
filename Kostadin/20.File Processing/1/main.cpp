#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
using namespace std;

#include "Tool.h";
int enterChoice();
void createTextFile( fstream& );
void updateRecord( fstream& );
void newRecord( fstream& );
void deleteRecord( fstream& );
void outputLine( ostream&, const Tool & );
int getTool( const char * const );

enum Choices { PRINT = 1, UPDATE, NEW, DELETE, END };
int main (){
//	ofstream outToolFile("Tools.dat", ios::binary);
//
//	if(!outToolFile)
//	{
//		cerr<<"File not opened. "<<endl;
//		exit(1);
//	}
//
//	Tool blankTool;
//
//	for(int i = 0; i < 100; i++)
//	{
//		outToolFile.write(reinterpret_cast< const char * >(&blankTool),sizeof(Tool));
//	}

	fstream inOutToolFile("Tools.dat", ios::in | ios::out);

	if(!inOutToolFile)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	int choice;

	while(( choice = enterChoice() ) != END)
	{
		switch(choice)
		{
		case PRINT:
			createTextFile( inOutToolFile ); break;
		case UPDATE:
			updateRecord( inOutToolFile ); break;
		case NEW:
			newRecord( inOutToolFile ); break;
		case DELETE:
			deleteRecord( inOutToolFile ); break;
		default:
			cerr << "Incorrect choice" << endl; break;
		}
		inOutToolFile.clear();
	}

	return 0;
}


int enterChoice()
{
	cout << "\nEnter your choice" << endl
	<< "1 - store a formatted text file of tools" << endl
	<< " called \"print.txt\" for printing" << endl
	<< "2 - update a tool" << endl
	<< "3 - add a new tool" << endl
	<< "4 - delete a tool" << endl
	<< "5 - end program\n? ";

	int menuChoice;
	cin>>menuChoice;
	return menuChoice;
}

void createTextFile( fstream &readFromFile )
{
	ofstream outPrintFile( "print.txt", ios::out );
	if ( !outPrintFile )
	{
		cerr << "File could not be created." << endl;
		exit(1);
	}

	outPrintFile << left << setw( 10 ) << "Tool #" << setw( 16 )
	<< "Tool Name" << setw( 11 ) << "Tool Count" << right
	<< setw( 10 ) << "Tool Cost" << endl;

	readFromFile.seekg( 0 );

	Tool tool;
	readFromFile.read( reinterpret_cast< char * >( &tool ),
			sizeof( Tool ) );

	while ( !readFromFile.eof() )
	{
		if(tool.getToolNumber() != 0)
		{
			outputLine( outPrintFile, tool );
		}

		readFromFile.read( reinterpret_cast< char * >( &tool ),
				sizeof( Tool ) );
	}
}

void updateRecord( fstream &updateFile )
{
	int toolNum = getTool("Enter tool to update");
	updateFile.seekg( ( toolNum - 1 ) * sizeof( Tool ) );

	Tool tool;
	updateFile.read( reinterpret_cast< char * >( &tool ),
			sizeof( Tool ) );

	if(tool.getToolNumber() != 0)
	{
		outputLine( cout, tool );
		cout << "\nEnter price up (+) or price down (-): ";
		double price;
		cin >> price;

		double oldPrice = tool.getToolPrice();
		tool.setToolPrice(oldPrice + price);
		outputLine( cout, tool );

		updateFile.seekp( ( toolNum - 1 ) * sizeof( Tool ) );

		updateFile.write( reinterpret_cast< const char * >( &tool ),
				sizeof( Tool ) );
	}

	else {
		cerr << "Account #" << toolNum
		<< " has no information." << endl;
	}

}

void newRecord( fstream &insertInFile )
{
	int toolNum = getTool("Enter tool to create");
	insertInFile.seekg( ( toolNum - 1 ) * sizeof( Tool ) );

	Tool tool;

	insertInFile.read( reinterpret_cast< char * >( &tool ),
			sizeof( Tool ) );

	if ( tool.getToolNumber() == 0 )
	{
		char toolName[20];
		int toolCount;
		double toolPrice;

		cout << "Enter tool name, tool count, price\n? ";
		cin >> setw( 15 ) >> toolName;
		cin >> setw( 10 ) >> toolCount;
		cin >> toolPrice;

		tool.setToolNumber(toolNum);
		tool.setToolName(toolName);
		tool.setToolCount(toolCount);
		tool.setToolPrice(toolPrice);

		insertInFile.seekp( ( toolNum - 1 ) * sizeof( Tool ) );

		insertInFile.write( reinterpret_cast< const char * >( &tool ),
				sizeof( Tool ) );
	}
	else // display error if account already exists
		cerr << "Account #" << toolNum
		<< " already contains information." << endl;
}

void deleteRecord( fstream &deleteFromFile )
{
	int toolNum = getTool("Enter tool to delete");
	deleteFromFile.seekg( ( toolNum - 1 ) * sizeof( Tool ) );

	Tool tool;
	deleteFromFile.read( reinterpret_cast< char * >( &tool ),
	sizeof( Tool ) );

	if(tool.getToolNumber() != 0)
	{
		Tool blankTool;
		deleteFromFile.seekp((toolNum - 1) * sizeof(Tool));
		deleteFromFile.write(reinterpret_cast<const char *>(&blankTool),sizeof(Tool));
		cout << "Tool #" << toolNum << " deleted.\n";
	}
	else
	{
		 // display error if record does not exist
		cerr << "Tool #" << toolNum << " is empty.\n";
	}
}

void outputLine( ostream &output, const Tool &tool )
{
	output << left << setw( 10 ) << tool.getToolNumber()
	<< setw( 16 ) << tool.getToolName()
	<< setw( 11 ) << tool.getToolCount()
	<< setw( 10 ) << setprecision( 2 ) << right << fixed
	<< showpoint << tool.getToolPrice() << endl;
}

int getTool(const char * const prompt)
{
	int toolNum;
	do
	{
		cout << prompt << " (1 - 100): ";
		cin >> toolNum;
	}while(toolNum < 1 || toolNum > 100);

	return toolNum;
}













