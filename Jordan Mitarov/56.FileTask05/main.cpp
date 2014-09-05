#include <iostream>
using namespace std;
#include <fstream>
#include<cstdlib>
#include <string>

int main()
{
	string word;

	ifstream readFile("read.txt",ios::in);

	if(!readFile)
	{
		cerr<<"File could not be opened";
		exit(1);
	}


	string s;
	while(!readFile.eof())
	{
		getline(readFile,s);
		word.append(" ");
		word.append(s);
		word.append(" ");
		//word.append("\n");
	}
	cout<<word;

	int position = word.find_first_of(" test ");

	while(position != string::npos)
	{
		position = word.find_first_of(" test");
		word.erase(position+1,5);
	}
	cout<<"\nabcd";
	cout<<word;

	return 0;
}
