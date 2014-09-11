//============================================================================
// Name        : Ex2_File_Lecture.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

#include "PhoneNumber.h"

int main()
{
	PhoneNumber phone(2,3,4,5,6,7,8);

//	cout<<"Enter number (333-4444) : ";
//	cin>>phone;

	phone.saveCombinations();

	return 0;
}
