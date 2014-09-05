//============================================================================
// Name        : StringsToIntegers.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

int main()
{
    char temp[200];
    int num;
    int sum = 0;

    cout<<"Please enter 4 numbers: " << endl;

    for (int i = 0; i < 4; ++i) {
		fgets (temp, 200, stdin);
		num=atoi(temp);
		sum += num;
	}

    cout<<"Sum of you number is: "<< sum <<endl;
    return 0;
}

