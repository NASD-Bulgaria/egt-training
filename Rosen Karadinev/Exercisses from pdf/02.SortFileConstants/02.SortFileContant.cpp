#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	fstream inNameFile("Names.txt", ios::in); // Чете от файл и принтира на конзолата
	ofstream sortNamesFile("sortNames.txt", ios::out); // Създава файл и пише в него

	if(!inNameFile && !sortNamesFile)
	{
		cerr <<"File could not be opened";
		exit(1);
	}

	string name;
	vector <string> names; // вектор с имена

	while (inNameFile >> name) // чете от inNameFile първия стринг (демек name)
	{
		names.push_back(name); // слага ги в вектора
	}

	sort(names.begin(), names.end()); // сортира вектора

	for(unsigned i = 0; i < names.size(); i++) // записва ги в новия файл sortNamesFile
	{
		sortNamesFile << names[i] << endl;
	}

	return 0;
}
