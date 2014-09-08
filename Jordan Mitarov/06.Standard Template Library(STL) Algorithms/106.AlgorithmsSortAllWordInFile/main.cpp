/*7. Sort all words in a text file. Write the result in other
text file.*/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{

	string word;
	vector<string> vecWord;
	ifstream readFile("readFile.txt",ios::in);

	if(!readFile)
	{
		cerr<<"File could not be load ";
	}


	while(readFile && !readFile.eof())
	{
		readFile >> word;
		vecWord.push_back(word);
	}

	sort(vecWord.begin(),vecWord.end());
	ofstream writeFile("writeFile.txt",ios::out);

	if(!writeFile)
	{
		cerr<<"File could not be resolved ";
	}

	for (unsigned int i = 0; i < vecWord.size(); i++)
	{
		writeFile << vecWord[i]<<endl;
	}




	return 0;
}
