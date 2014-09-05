//============================================================================
// Name        : ReverseOrder.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "List.h"

int main() {
	List<char> list;
	srand(time(NULL));

	for (int i = 0; i < 10; ++i) {
		list.insertAtBack(rand()%26+65);
	}

	list.print();
	list.reverse();
	list.print();

	return 0;
}
