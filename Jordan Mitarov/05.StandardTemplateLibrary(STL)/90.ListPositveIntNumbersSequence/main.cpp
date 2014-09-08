/*1. Write a program that reads from the console a
sequence of positive integer numbers. The
sequence ends when the number 0 is entered.
Calculate and print the sum and average of the
elements of the sequence. Use linked list.*/

#include <iostream>
#include <list> // list class-template definition
#include <algorithm> // copy algorithm
#include <iterator> // ostream_iterator
using namespace std;


template <typename T>
list<int> putNumberInList(list<T> &listRef);
template<typename T>
void printList(list<T> &listRef);
template<typename T>
int calculateSum(list<T> &listRef);
template<typename T>
void sortList(list<T> &listRef);
template<typename T>
double calculateAver(list<T> &listRef,int result);


int main()
{
	double result;
	list<int> values;

	putNumberInList(values);
	printList(values);
	cout<<"\nThe sum is: ";
	result = calculateSum(values);
	cout<<result;
	result = calculateAver(values,result);
	cout<<"\nThe average is: ";
	cout<<result;
	sortList(values);

	return 0;
}

template <typename T>
list<int> putNumberInList(list<T> &listRef) //funkciq za pylnene na lista
{
	int num ;

	while(num!=0)
	{
		cout<<"Enter number: ";
		cin>>num;
		if(num==0)
		{
			break;
		}
		listRef.push_back(num);
	}
	cout<<"Program stop \n";

	return listRef;
}

template<typename T>
void printList(list<T> &listRef)  //funkciq za printirane na lista
{
	if(listRef.empty())
	{
		cout<<"List is empty";
	}
	else
	{
		cout<<"The list is: ";
		 ostream_iterator< T > output( cout, " " );
		 copy( listRef.begin(), listRef.end(), output );
	}
}

template<typename T>
int calculateSum(list<T> &listRef)
{
	int sum = 0;

	for(list<int>::iterator it = listRef.begin();it!=listRef.end();it++)
	{
		sum = sum + *it;
	}

	return sum;
}

template<typename T>
double calculateAver(list<T> &listRef,int sum)
{
	int length = listRef.size();

	double res = sum / length;

	return res;
}

template <typename T>
void sortList(list<T> &listRef)
{
	listRef.sort();
	cout<<"\nThe sorted list is: ";

	ostream_iterator< T > output( cout, " " );
	copy( listRef.begin(), listRef.end(), output );
}
