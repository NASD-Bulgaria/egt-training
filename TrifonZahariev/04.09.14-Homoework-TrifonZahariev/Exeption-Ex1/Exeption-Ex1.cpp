//============================================================================
// Name        : Exeption-Ex1.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int a = 5;
	double b = 5.5;

	try{
		throw true?a:b;
	}
	catch(int a){
		cout << "Catched int"<< endl;
	}
	catch(double b){
		cout << "Catched double"<< endl;
	}


	return 0;
}
