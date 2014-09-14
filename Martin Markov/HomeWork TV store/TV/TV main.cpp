//============================================================================
// Name        : TV.cpp
// Author      : Martin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "televisors.h"
#include <fstream>
#include <cstdlib>
#include <sstream>
using namespace std;

int pickChoice();
void addTV(vector<televisors> &);
void saveTV(ofstream& output,vector<televisors>& vect);
void print(ifstream &input);
void findBrand(ifstream& in);
void findInch(ifstream& in);

int main() {

	ofstream out("TV.txt",ios::out);
			if(!out)
			{
				cout<<"file not found";
				return -1;
			}


	ifstream in("TV.txt",ios::in);
	if(!in)
	{
		cout<<"file not found";
		return -1;
	}


	vector<televisors> newTV;
		int choice;
		while((choice = pickChoice()) !=6)
		{
			switch(choice)
			{
			case 1:
				addTV(newTV);
				break;
			case 2:
				saveTV(out,newTV);
				out.close();
				break;
			case 3:
				print(in);
				break;
			case 4:
				findBrand(in);
				break;
			case 5:
				findInch(in);
				break;
			default:cout<<"ERROR"<<endl;
			break;
			}
		}


	return 0;
}
	int pickChoice()
	{
		int number;
		cout<<"Натиснете 1 за въвеждане на нов модел"<<endl;
		cout<<"Натиснете 2 за да го добавите в базата данни"<<endl;
		cout<<"Натиснете 3 за да видите наличните модели "<<endl;
		cout<<"Натиснете 4 за избор на телевизор по марка"<<endl;
		cout<<"Натиснете 5 за избор на телевизор по инчове"<<endl;
		cout<<"Натиснете 6 за изход от програмата"<<endl;
		cin>>number;
		return number;

	}

void addTV(vector<televisors> &myVector)
	{
	string marka;
	string model;
	string cvqt;
	int hertz;
	double inch;


	televisors *TV;
cout<<"Моля въведете марка: ";
cin>>marka;
cout<<"Моля въведете модел: ";
cin>>model;
cout<<"Моля въведете цвят: ";
cin>>cvqt;
cout<<"Моля въведете херцове: ";
cin>>hertz;
cout<<"Моля въведете инчове: ";
cin>>inch;
cout<<endl;

TV = new televisors;
TV->setBrand(marka);
TV->setModel(model);
TV->setColor(cvqt);
TV->setHertz(hertz);
TV->setInch(inch);


myVector.push_back(*TV);
	}
void saveTV(ofstream& output,vector<televisors>& vect)
{
	string test = "";
	vector<televisors>::iterator it;
	for(it = vect.begin();it != vect.end();it++)
	{
		test=(it->printTV());
		output<<test;
		test = "";
	}

}
void print(ifstream &input)
{
	while(!input.eof())
	{
		string temp;
	  getline(input,temp);
	  cout<<temp<<endl;
	   temp="";
	}
}
void findBrand(ifstream& in)
{
	string brand;
	cout<<"Какъв телевизор желаете ";
	cin>>brand;
	in.clear();
	in.seekg(ios::beg);
	while(!in.eof())
	{
		string temp;
		getline(in,temp);
		int unsigned index = temp.find(brand);
		if(index != string::npos)
		{
			cout<<"Наличните ни телевизори от тази марка са: "<<endl<<temp<<endl;
			break;

		}
		temp= "";
	}
}
void findInch(ifstream& in) //Още дойзпипване когато остане време
{
	vector<string> allObj;
	in.clear();
	in.seekg(ios::beg);

	while(!in.eof())
	{
		string temp;
		getline(in,temp);
		allObj.push_back(temp);
		temp="";
	}


	in.clear();
	in.seekg(ios::beg);
	int doublePosition=0;
	int whoRow=0;
	while(!in.eof())
	{
		string temp;
		in >> temp;
		doublePosition++;
		if(doublePosition==5)
		{
			whoRow++;
			doublePosition=0;
		}
				if(doublePosition==4)
						{
					double number;
					double inch;
					cout<<"Колко инчов телевизор желаете"<<endl;
					cin>>inch;
					number = atof(temp.c_str());
						if (number==inch)
						{
							cout<<"Наличните "<<inch<<"-инчови телевизори са: "<<endl<<allObj[whoRow]<<endl;
							break;
						}


		}
	}
}

