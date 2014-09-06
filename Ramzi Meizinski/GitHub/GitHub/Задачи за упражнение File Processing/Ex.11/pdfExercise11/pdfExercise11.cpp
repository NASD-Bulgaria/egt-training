//============================================================================
// Name        : pdfExercise11.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;


int main() {
	ifstream inFile ("test.txt", ios::in);
	 ifstream inputFile("words.txt", ios::in);
	 fstream outFile ("result.txt", ios::out | ios::in);
	  if (!inFile && !outFile && !inputFile)
	  {
		  cerr << "File could not be opened." << endl;
		  exit(1);
	  }
	  string s;
	  vector<string> words;
	  vector<string> test;
	  while (inFile >> s)
	  {
		  if (isalpha(s[s.length()-1]) == false)
		  	 {
		  		  s.erase (s.length()-1);
		  	 }
		  	  test.push_back(s);
	  }
	  while (inputFile >> s)
	  	  {
	  		  if (isalpha(s[s.length()-1]) == false)
	  		  	 {
	  		  		  s.erase (s.length()-1);
	  		  	 }
	  		  	  words.push_back(s);
	  	  }

	  sort( words.begin(), words.end() );
	  words.erase( unique( words.begin(), words.end() ), words.end() );

	  outFile << setw(20) << "WORD" << setw(20) << "HOW MANY TIMES" << endl;
	  int count;
	    for (unsigned int i=0; i<words.size();i++)
	    {count = 0;
	    for (unsigned int j=0; j<test.size(); j++)
	  	  {
	  		  if (words[i] == test[j])
	  		  {
	  			 count++;
	  		  }
	  	  }
	  	  outFile << setw(20) << words[i] << setw(13) << count << setw(7) << " times" << endl;
	  	 }

//	  if( remove( "myfile.txt" ) != 0 )
//	      perror( "Error deleting file" );
//	    else
//	      puts( "File successfully deleted" );
//	  rename("myfile.dat", "newfile.dat");
	return 0;
}
