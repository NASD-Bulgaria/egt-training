/*10. Write a program that removes from a text file all words that are contained by
given another text file. Handle all possible exceptions in your methods.*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iterator>
using namespace std;

vector<string> readData(ifstream &);
void uniqueElement(vector<string> &,vector<string> &);

int main()
{
	ifstream readFile("read.txt",ios::in);
	ifstream readFile2("read2.txt",ios::in);
	ofstream writeFile("write.txt",ios::out);

	vector<string> vecFirst;
	vector<string> vecSecond;
	vecFirst = readData(readFile);
	vecSecond = readData(readFile2);

	sort(vecFirst.begin(),vecFirst.end());
	sort(vecSecond.begin(),vecSecond.end());

	uniqueElement(vecFirst,vecSecond);

	cerr<<"The program is Ready";

}

vector<string> readData(ifstream & file)
{
	string fileWord;

	if(!file)
	{
		cerr<<"File could not be opened";
		exit(1);
	}

	vector<string> vec;

	while(file && !file.eof())
	{
		file >> fileWord;
		vec.push_back(fileWord);
	}
	/*cout<<"VecOne: "<<endl;
	for (unsigned int i = 0; i < vec.size(); ++i) {
		cout<<vec[i]<<" ";
	}*/

	return vec;
}

void uniqueElement(vector<string> &vecOne,vector<string> &vecTwo)
{
	vector<string> vecThree;

	set_union(vecOne.begin(),vecOne.end(),vecTwo.begin(),
			vecTwo.end(),back_inserter(vecThree)); //obedinqvam dvata vectora v treti.

/*	cout<<"\nThe union has "<<(vecThree.size())<< " elements:\n";
	for(unsigned int i = 0; i<vecThree.size();i++)
	{
		cout<<vecThree[i]<<" ";
	}*/

	 vector<string> vecFour;  //syzdavam 4etvyrti vector
	 unique_copy (vecThree.begin(), vecThree.end(),back_inserter(vecFour)); //kazvam unique elementite da gi kopira
																			//v 4etvyrtiq vector
	 ofstream writeNewFile("write.txt",ios::out);  //syzdavam file v koito da se zapishat dannite

	 for(unsigned int i=0; i<vecFour.size();i++)  //obhojdam 4etvyrtiq vektor i kazvam da zapishe ve4e novite elementi v noviq fail
	 {
		 writeNewFile << vecFour[i]<<"\n";
	 }

}


