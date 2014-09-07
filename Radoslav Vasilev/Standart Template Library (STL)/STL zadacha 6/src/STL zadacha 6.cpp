//============================================================================
// Name        : STL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <set>

using namespace std;


int main()
{
	multiset<int>::iterator it;
	multiset <int> numbers;
	int array[9]= {3,4,4,2,3,3,4,3,2};
	for(int i = 0;i < 9;i++ )
	{
		numbers.insert(array[i]);
	}
	it = numbers.begin();
	int count = 1;
	while(it!=numbers.end())
	{
		int firstE = *it;
		it++;
		int nextE = *it;
		if(firstE== nextE)
		{
			count++;
		}
		else
		{
			cout<<firstE<<" -> "<<count<<endl;
//			count= 1;
			if(count%2==0)
		}
	}





	return 0;
}

