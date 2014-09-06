//============================================================================
// Name        : lineByLine.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

int main() {
	ifstream file1("file1.txt", ios::in);
	ifstream file2("file2.txt",ios::in);

	if(!file1 && !file2)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	string s1,s2;
	int numb1=0;
	int numb2=0;
	vector <string> line1;
	vector <string> line2;
	while (!file1.eof())
	{
		getline(file1,s1);
		numb1++;
		line1.push_back(s1);
	}
	while(!file2.eof())
	{
		getline(file2,s2);
		numb2++;
		line2.push_back(s2);
	}

	cout << "Different lines are: ";


	//Tuk pravq proverka koi fail e s po-malko redove, i sravnqvame tolkova reda
	//kolkoto ima po-malkiq fail, zashtoto v protiven sluchai shte grymne.

	if(numb1 <= numb2){
	for (unsigned int i =0; i<line1.size();i++)
	 {
		 if (line1[i] != line2[i])
			 cout << i+1 << " ";
	 }
	}
	else
	{
		for (unsigned int i =0; i<line2.size();i++)
			 {
				 if (line1[i] != line2[i])
					 cout << i+1 << " ";
			 }

	}

return 0;
}
