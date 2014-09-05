#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;

int main()
{
	fstream inNameFile("read.txt", ios::in);
	ofstream outNameFile("sortnewFile.txt", ios::out);

	if (!inNameFile && !outNameFile)
	{
		cerr << "Cannot open the File";
		exit(1);
	}
	string name;
	vector<string> names;

	while (inNameFile >> name)
	{
		names.push_back(name);
	}
	sort(names.begin(), names.end());

	for (unsigned i = 0; i < names.size(); i++)
	{
		outNameFile << names[i] << endl;
	}

	return 0;
}
