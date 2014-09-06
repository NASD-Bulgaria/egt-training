//============================================================================
// Name        : removeWords.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string.h>
using namespace std;

int main() {

 ifstream inFile ("textFile.txt", ios::in);
 ifstream inputFile("givenAnotherTextFile.txt", ios::in);
 ofstream outFile ("result.txt", ios::out);
  if (!inFile && !outFile && !inputFile)
  {
	  cerr << "File could not be opened." << endl;
	  exit(1);
  }
  string s,result;
  vector<string> words1;
  vector<string> words2;
  while(inFile >> s)
  {
	  if (isalpha(s[s.length()-1]) == false)
	 {
		  s.erase (s.length()-1);
	 }
	  words1.push_back(s);
  }

  while(inputFile >> s)
    {
  	  if (isalpha(s[s.length()-1]) == false)
  	 {
  		  s.erase (s.length()-1);
  	 }
  	  words2.push_back(s);
    }
int count;
  for (unsigned int i=0; i<words1.size();i++)
  {count = 0;
	  for (unsigned int j=0; j<words2.size(); j++)
	  {
		  if (words1[i] == words2[j])
		  {
			 count++;
		  }
	  }
	  if (count == 0)
	  {
	  outFile << words1[i] << " ";
	  }

  }
	return 0;
}
