//8.There are two text files. Display all words that
//present only in one of the files.

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	string wordOne;
	string wordTwo;

	vector<string> vecOne;
	vector<string> vecTwo;
	vector<string> vecThree;
	vector<string> vecFour;
	ifstream readFile("readFile.txt",ios::in);
	ifstream readFile2("readFile2.txt",ios::in);

	//ostream_iterator< int > output( cout, " " );

	if(!readFile)
	{
		cerr<<"One of the files could not be opened";
	}

	while(readFile && !readFile.eof())
	{
		readFile >> wordOne;
		vecOne.push_back(wordOne);
	}

	while(readFile2 && !readFile2.eof())
	{
		readFile2 >> wordTwo;
		vecTwo.push_back(wordTwo);
	}

	sort(vecOne.begin(),vecOne.end());
	sort(vecTwo.begin(),vecTwo.end());

	set_union(vecOne.begin(),vecOne.end(),vecTwo.begin(),
				vecTwo.end(),back_inserter(vecThree)); //obedinqvam dvata vectora v treti.

	//za da izpolzvame unique trqbva da gi sortirame vektorite,ina4e ne se polu4ava efekta
	unique (vecThree.begin(), vecThree.end());

	 for(unsigned int i=0; i<vecThree.size();i++)
	 {
		 cout << vecThree[i]<<endl;
	 }

	return 0;
}
