#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

void enterIntNumbers();
void print(list<int>);

int main()
{

	enterIntNumbers();

	return 0;
}

void enterIntNumbers()
{
	list<int> sortedList;

	int num;
	while(num!=0)
	{
		cout<<"Enter number: ";
		cin>>num;
		if(num==0)
		{
			break;
		}
		sortedList.push_back(num);
	}

	cout<<"The list before sort is: ";
	print(sortedList);
	cout<<endl;
	sortedList.sort();
	cout<<"The list after sort is: ";
	print(sortedList);
}

void print(list<int> printSort)
{
	cout<<"The sorted list is: ";
	ostream_iterator< int > output( cout, " " );
	copy( printSort.begin(), printSort.end(), output );
}


