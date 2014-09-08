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
	int array[9] = {3, 4, 4, 2, 3, 3, 4, 3, 2};
	int counter = 0;
	int temp;

	for (int i = 0; i < 9; ++i)
	{
		n.insert(array[i]);
	}

	multiset<int>::iterator it;
	temp = *n.begin();
	for(it = n.begin();it != n.end(); ++it)
	{
		if (temp ==*it )
		{
			temp = *it;
			counter++;
		}
			else
			{
				cout<<temp<<" - > "<<counter<<endl;
				counter = 1;
				temp = *it;
			}
	}
	cout<<temp<<" - > "<<counter<<endl;

	return 0;
}
