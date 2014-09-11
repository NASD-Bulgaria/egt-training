//============================================================================
// Name        : Ex1_File_Lecture.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

# include "Items.h"

void print(Items);
int enterChoice();
void createTextFile();
void add(fstream &, Items );
void updating(fstream &, Items);
void del(fstream &, Items);
void initialization(fstream &);

int main()
{
	Items item1(1, "neshto1", 22.2, 50);
	Items item2(2, "neshto2", 33.5, 20);
	Items item3(3, "neshto3", 55.5, 40);
	Items item4(5, "neshto4", 55.5, 20);

	Items update(2, "neshto2", 33.0, 25);

	fstream inOut( "hardware.dat", ios::out | ios::binary );
	if(!inOut)
	{
		cout<<"Error opening file!";
		return -1;
	}

	initialization(inOut);

	int choice = enterChoice();
	while(choice!=5)
	{
		switch(choice)
		{
		case 1 : createTextFile(); break;
		case 2 :
			{
				updating(inOut, update);
				inOut.clear();
			}break;
		case 3 :
			{
				add(inOut, item1);
				inOut.clear();
				add(inOut, item2);
				inOut.clear();
				add(inOut, item3);
				inOut.clear();
				add(inOut, item4);
				inOut.clear();
				Items item;
				add(inOut, item);
			}break;
		case 4 :
			{
				del(inOut, item1);

			}break;
		case 5 : break;
		default : cout<<"Incorrect choice!"<<endl; break;
		}
		inOut.clear();
		choice = enterChoice();
	}

	return 0;
}

void print(Items item)
{
	cout<<"Number : "<<item.getNumber()<<endl;
	cout<<"Name : "<<item.getName()<<endl;
	cout<<"Price : "<<item.getPrice()<<endl;
	cout<<"Count : "<<item.getCount()<<endl;
	cout<<endl;
}

int enterChoice()
{

	cout << "\nEnter your choice" << endl
	<< "1 - Create text file \"print.txt\"" << endl
	<< "2 - update" << endl
	<< "3 - add" << endl
	<< "4 - delete" << endl
	<< "5 - exit\n? ";

	int menuChoice;
	cin >> menuChoice; // input menu selection from user
	return menuChoice;
}

void createTextFile()
{
	Items item;
	ifstream in("hardware.dat", ios::out);
	if(!in)
	{
		cout<<"Error opening file 1!";
		exit(1);
	}
	ofstream out("print.txt", ios::out);
	if(!out)
	{
		cout<<"Error opening file 1!";
		exit(1);
	}

	in.seekg(0);

	while (!in.eof())
	{
		//print(item);
		if(item.getNumber() != 0)
		{
			out<<"Number : "<<item.getNumber()<<endl;
			out<<"Name : "<<item.getName()<<endl;
			out<<"Price : "<<item.getPrice()<<endl;
			out<<"Count : "<<item.getCount()<<endl;
			out<<endl;
		}
		in.read(reinterpret_cast< char *>(&item), sizeof(Items));
	}
	out.close();
}

void add(fstream &out, Items obj)
{
	out.seekp((obj.getNumber()-1) * sizeof(Items));
	out.write(reinterpret_cast< const char *>(&obj),sizeof(Items));
}

void updating(fstream &out, Items obj)
{
	out.seekp((obj.getNumber()-1) * sizeof(Items));
	out.write(reinterpret_cast< const char *>(&obj),sizeof(Items));
}

void del(fstream &out, Items obj)
{
	Items item;
	out.seekp((obj.getNumber()-1) * sizeof(Items));
	out.write(reinterpret_cast< const char *>(&item),sizeof(Items));
}

void initialization(fstream &out)
{
	Items item;
	for (int i=0; i<100; i++)
	{
		out.seekp(i*sizeof(Items));
		out.write(reinterpret_cast<const char *>(&item), sizeof(Items));
	}
}
