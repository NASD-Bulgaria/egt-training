/*Write a program that replaces all occurrences of the substring "start" with the substring
"finish" in a text file.&& Modify the solution of the previous problem to replace only whole words.*/

#include <iostream>
using namespace std;

#include <fstream>
#include <cstdlib> // for exit(1)

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
		getline(readFile,s); //v readFile, zapisvame s
		word.append(" ");
		word.append(s);     // konkatenirame na word i zalepqme s
		word.append(" ");  // nakraq na reda konkatenirame endl, za da izlizat na nov red
		word.append("\n");
	}
	cout<<"The expression with start is: "<<endl;
	cout<<word;

	int position = word.find(" start "); // namirame na koq poziciq e start

	while(position != string::npos)
	{
		word.replace(position,7," finish ");   // replace ot poziciqta 5 na broi simvola sys finish
		position = word.find(" start ",position+1); // replace kyudeto nameri poziciqta i zapo4va start
	}

	ofstream writeFile("write.txt",ios::out);

	if(!writeFile)
	{
		cerr<<"File could not be resolved";
		exit(1);
	}

	writeFile << word;  //vkarvame dumata v writeFile, bez cikyl za6toto samo se vkarva, i cikyla neznae kyde e kraq i 6e napravq bezkraen cikyl


	return 0;
}
