#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;


int main()
{
	int count = 0;
	string row;

	ifstream inFile("TextTest.txt", ios::in);
	ofstream outFile("NewTextTest.txt", ios::out);

	if ( !inFile ){
		cerr << "File could not be opened Text.txt" << endl;
		exit( 1 );
	} // end if

	if ( !outFile ){
		cerr << "File could not be opened NewText.txt" << endl;
		exit( 1 );
	} // end if

	while(getline(inFile, row))
	{
		count++;
		outFile << count << " " << row << endl;


	}



	return 0;
}
