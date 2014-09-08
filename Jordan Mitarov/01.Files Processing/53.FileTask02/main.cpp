/*2. Write a program that reads a text file containing a list of strings,
sorts them and saves them to another text file. Example:
Ivan George
Peter Ivan
Maria Maria
George Peter*/

#include <iostream>
using namespace std;

#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

int main()
{

	string name;

	ifstream readFile("read.txt",ios::in);

	if(!readFile)
	{
		cerr<<"Read File could not be opened";
		exit(1);
	}

	vector<string> vec;

	while(readFile && !readFile.eof())
	{
		readFile >> name;  // ot faila vkarvam v promenlivata name
		vec.push_back(name);  //vkarvam vyv vektora gotovata promenliva name
	}

	sort(vec.begin(),vec.end());  //sortirame ot na4aloto na vectora do kraq

	ofstream writeFile("write.txt",ios::out);

	if(!writeFile)
	{
		cerr<<"Read File could not be opened";
		exit(1);
	}

	for(unsigned int i = 0; i<vec.size();i++)  //obhojdame vektora
	{
		writeFile << vec[i]<<endl;  //zapisvame dannite ot vektora v write.txt
	}

	return 0;
}
