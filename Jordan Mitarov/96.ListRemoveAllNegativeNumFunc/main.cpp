#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>
using namespace std;

struct is_negative
{
  bool operator() (const int& value)
  {
	  return (value<=0);
  }
};

void printList(list<int> &);
list<int> enterNumbers(int,list<int> &);
void removeNegativeElement(list<int> &);

int main()
{
	list<int> myList;
	int size = 0;
	cout<<"How number you want to enter? ";
	cin>>size;

	myList = enterNumbers(size,myList);
	cout<<"List before remove negative values: ";
	printList(myList);
	removeNegativeElement(myList);
	cout<<"\nList after remove negative values: ";
	printList(myList);

	return 0;
}

void printList(list<int> &listRef)
{
	ostream_iterator< int > output( cout, " " );
	copy( listRef.begin(), listRef.end(), output );
}

list<int> enterNumbers(int size,list<int> &listRef)
{
	int num;

	for(int i = 0; i < size; i++)
	{
		cout<<"Enter the number: ";
		cin>>num;
		listRef.push_back(num);
	}

	return listRef;
}

void removeNegativeElement(list<int> &listRef)
{
	list<int>::iterator it;
	for(it=listRef.begin();it!=listRef.end();it++)
	{
		listRef.remove_if(is_negative());
	}
}
