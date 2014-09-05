//============================================================================
// Name        : core1-STL-5ta-zadacha.cpp
// Author      : Ivan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<list>
#include<algorithm>
#include<iterator>
using namespace std;

int main() {
	int integer;
	list <int> integers;
	cout<<"Enter integers until you enter 0 ";
	while(integer!=0)
	{
		cin>>integer;
		integers.push_back(integer);
	}
	integers.sort();
	if ( integers.empty() ) //
	      cout << "List is empty";
	   else
	   {
	      ostream_iterator<int> output( cout, " " );
	      copy( integers.begin(), integers.end(), output );
	   }

	return 0;
}


