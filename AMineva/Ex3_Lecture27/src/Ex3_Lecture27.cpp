//============================================================================
// Name        : Ex3_Lecture27.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iterator>
using namespace std;

int genNum()
{
	return rand()%10;
}

int main()
{
	srand(time(NULL));
	vector<int>v(5);
	generate(v.begin(),v.end(),genNum);
	sort(v.begin(),v.end());
	reverse(v.begin(), v.end());
	ostream_iterator<int> output( cout," ");
	copy(v.begin(), v.end(), output);

	return 0;
}
