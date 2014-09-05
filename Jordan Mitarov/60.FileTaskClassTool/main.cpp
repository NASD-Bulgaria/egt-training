/*1. You are the owner of a hardware store and need to
keep an inventory that can tell you what different
tools you have, how many of each you have on
hand and the cost of each one. Write a program
that initializes the random-access file hardware.dat
to 100 empty records, lets you input the data
concerning each tool, enables you to list all your
tools, lets you delete a record for a tool that you no
longer have and lets you update any information in
the file. The tool identification number should be
the record number.*/

#include <iostream>
#include<fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

#include "Tool.h"

void menu(fstream &);
void outputLine( ostream&, const Tool & ); // prototype
void inputData(fstream &);
void readData(fstream &);

int main()
{

	fstream inToolProduct("ToolProduct.dat",ios::in | ios::out | ios::binary);

	if(!inToolProduct)
	{
		cerr<<"File could not be opened";
		exit(1);
	}


	menu(inToolProduct);

	return 0;
}

void menu(fstream &file)
{
	char choice;


	cout<<"Do you want INPUT data or READ data in the file? \nEnter I or R for choice: ";
	cin>>choice;
	choice = toupper(choice);

	while(choice!='R' && choice!='I')
	{
		cout<<"Invalid choice: Enter choice: ";
		cin>>choice;
		choice = toupper(choice);
	}

	if(choice=='I')
	{
		inputData(file);
	}

	if(choice=='R')
	{
		readData(file);
	}
}

void outputLine( ostream &output, const Tool &record )
{
   output << left << setw( 10 ) << record.getRec()
      << setw( 16 ) << record.getTool()
      << setw( 5 ) << record.getQuant()
      << setw( 10 ) << setprecision( 2 ) << right << fixed
      << showpoint << record.getPrice()<<"$" << endl;
} // end function outputLine

void inputData(fstream &file)
{
		int record;
		string toolName;
		int quantity;
		double price;

		cout<<"Enter record number: -1 to End: ";
		Tool toolProd;
		cin>>record;


		while(record > 0)
		{
			cout<<"Enter ToolName: ";
			cin.ignore();
			getline(cin,toolName);
			//cin>>setw(15)>>toolName;
			cout<<"Enter Quantity: ";
			cin>>setw(10)>>quantity;
			cout<<"Enter price: ";
			cin>>setw(10)>>price;

			toolProd.setRec(record);
			toolProd.setTool(toolName);
			toolProd.setQuant(quantity);
			toolProd.setPrice(price);

			file.seekp((toolProd.getRec()-1) * sizeof(Tool));

			file.write(reinterpret_cast<const char *> (& toolProd),sizeof(Tool));

			cout<<"Enter record number: -1 to End: ";
			cin>>record;
		}
		menu(file);


}

void readData(fstream &file)
{
	Tool toolProd;

	cout<<"Record #"<<setw(11)<<right<<"Tool Name"<<setw(15)<<right<<"Quantity"<<setw(7)<<right<<"Price"<<endl;

	//read first record from file
	file.read(reinterpret_cast< char * > (& toolProd),sizeof(Tool));

	ifstream readfile("ToolProduct.dat",ios::in);

	while(readfile && !readfile.eof())
	{
		if(toolProd.getRec()!=0)
		{
			outputLine(cout, toolProd);
		}
		//read next from file
		readfile.read(reinterpret_cast< char * > (& toolProd),sizeof(Tool));
	}
}
