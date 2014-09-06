//============================================================================
// Name        : stringStream.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;

int main() {

	 string str = "Test String";                      //Ex.3
		  string result = "";
		  char c;
		    for (int i = str.length() - 1; i >= 0; i--)
		  {
			  c=str[i];
		    if (islower(c)){
		    	c = toupper(c);
		    }
		    else{
		    	c = tolower(c);
		    }
		    result = result.append(1,c);

		  }
		  for (unsigned int i=0; i < str.length(); ++i)
		  	  {
			  	  cout << result.at(i);
		  	  }

	return 0;
}
