//============================================================================
// Name        : core1-algorithm-1va-zadacha.cpp
// Author      : Ivan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<stdlib.h>
#include<ctime>

using namespace std;
int randomNum();


int main() {
	vector<int>ints(10);
	ostream_iterator< int > output( cout, " " );
	vector<int>::reverse_iterator p;
	generate( ints.begin(), ints.end(), randomNum );
	copy( ints.begin(), ints.end(), output );
	sort(ints.begin(),ints.end());
	cout<<endl;
	copy( ints.begin(), ints.end(), output );
	cout<<endl;
	p=ints.rbegin();
	while(p!=ints.rend())
	{
		cout<<*p<<" ";
		p++;
	}



	return 0;
}
int randomNum()
{
	int num=rand()%100;
	return num;
}
