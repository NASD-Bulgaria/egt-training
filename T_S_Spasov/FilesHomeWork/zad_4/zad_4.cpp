//============================================================================
// Name        : zad_4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "!!!Zad_4!!!" << endl; // prints !!!Hello World!!!
	int countArr[10] = {0};
	int testNumber, num;
	cout << "Input test number: ";
	cin >> testNumber;

	while(testNumber != 0){
		countArr[testNumber%10]++;
		testNumber /= 10;
	}
  for(int i=0; i < 10; i++){
	  cout << i <<" "<< countArr[i]<<endl;
  }
	return 0;
}
