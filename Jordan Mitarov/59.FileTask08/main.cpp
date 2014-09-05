#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>
using namespace std;

vector<string> readData(ifstream &);
void countElements(vector<string> &,vector<string> &);

int main()
{

	ifstream readFileWord("words.txt",ios::in);
	ifstream readFileText("text.txt",ios::in);

	vector<string> vecOne;
	vector<string> vecTwo;
	vecOne = readData(readFileWord);
	vecTwo = readData(readFileText);

	countElements(vecOne,vecTwo);

	cerr<<"The program is ready ";
	return 0;
}

vector<string> readData(ifstream &file)
{
	string fileWord;

	if(!file)
	{
		cerr<<"File could not be resolved";
		exit(1);
	}

	vector<string> vec;

	while(file && !file.eof())
	{
		file >> fileWord;
		vec.push_back(fileWord);
	}


	return vec;
}

void countElements(vector<string> &vecOne,vector<string> &vecTwo)
{
	int count = 0;
	vector<string> vecThree;
	unique_copy (vecOne.begin(), vecOne.end(),back_inserter(vecThree));
	ofstream writeNewFile("write.txt",ios::out);


	for(unsigned int i = 0;i<vecThree.size();i++)
	{
		count = 0;
		for(unsigned int j=0;j<vecTwo.size();j++)
		{
			if(vecThree[i] == vecTwo[j])
			{
				count++;
			}
		}
//		if(count!=0)
//		{
			writeNewFile << vecThree[i] << " = "<<count<<"\n";
//		}
	}
}

