//============================================================================
// Name        : 2Print-RorAY.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	string first = "vasilr kaz na onay";
	string second = "koir kaza tova maq";
	string third(first,second);
	cout << third;
	int position = 0;
	int position2 = third.find(" ");

	while(position != string::npos){
		string word;
		word = third.substr(position, position2 - position );
		if(word.find_last_of("r") || word.find_last_of("ay")){
			cout << word;
		}
	}



	return 0;
}
