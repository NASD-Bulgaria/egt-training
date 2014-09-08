//============================================================================
// Name        : ex_STL6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iterator>
#include <set>
using namespace std;

int main()
{
	multiset<int> n;
	multiset<int> n1;
	int array[9] = {3, -1, 4, -2, 3, -3, 4, 3, -2};


	for (int i = 0; i < 9; ++i)
	{
		n.insert(array[i]);
	}

	for(multiset<int>::iterator it = n.begin();it != n.end(); ++it)
	{
		if (*it >= 0)
		{
			n1.insert(*it);
		}
	}

	for(multiset<int>::iterator it = n1.begin();it != n1.end(); ++it)
	{
		cout<< *it<< " ";
	}


	return 0;
}
