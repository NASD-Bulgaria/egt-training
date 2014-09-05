//============================================================================
// Name        : Exeption-Ex3.cpp
// Author      : Trifon Zahariev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "DestructorsView.h"

int main() {


	try {
		DestructorsView test;
		throw exception();
	}
	catch(exception e){
		cout << e.what();
	}

	cout << endl;

	try {
			throw exception();
		}
		catch(exception e){
			cout << e.what();
		}
		DestructorsView test1;


	return 0;
}
