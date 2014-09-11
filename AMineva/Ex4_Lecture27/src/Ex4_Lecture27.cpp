//============================================================================
// Name        : Ex4_Lecture27.cpp
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
#include <functional>
using namespace std;

int genNum()
{
	return rand()%100;
}

bool myfunction (int a, int b, int c)
{
  return (a>b)&&(b>c);
}

int main()
{
	srand(time(NULL));
	vector<int>v(10);
	vector<int>tempV(3);
	vector<int>sortV(3);
	generate(v.begin(),v.end(),genNum);
	ostream_iterator<int> output( cout," ");
	vector<int>::iterator it;
	it = adjacent_find (v.begin(), v.end(), myfunction);
	cout<<*it;
	for(unsigned i=0; i<v.size()-2; i++)
	{
		copy(v.begin()+i,v.begin()+i+3,sortV.begin());
		sort(sortV.begin(), sortV.end());
		reverse(sortV.begin(), sortV.end());
		if(tempV==sortV)
		{
			cout<<endl;
			copy(tempV.begin(), tempV.end(), output);
			break;
		}
	}
	return 0;
}
