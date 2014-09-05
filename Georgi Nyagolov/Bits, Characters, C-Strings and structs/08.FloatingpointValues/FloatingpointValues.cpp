//============================================================================
// Name        : FloatingpointValues.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    char temp[200];
    double num;
    double sum = 0;

    cout<<"Please enter 4 double numbers: " << endl;

    for (int i = 0; i < 4; ++i) {
    	fgets (temp, 200, stdin);
		num = atof(temp);
		sum += num;
	}

    cout<<"Sum of you number is: "<< sum <<endl;
    return 0;

}
