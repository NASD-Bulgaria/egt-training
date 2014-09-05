/*Write a program that merges two ordered list
objects of integers into a single ordered list object of
integers.*/

#include <iostream>
using namespace std;

#include "List.h"

template <typename T>
void reverseOrder(List<T> &first,List<T>&second)
{
	List<T> tempfirst(first); //create copy of first
	T value;

	while(!tempfirst.isEmpty())
	{
			tempfirst.removeFromBack(value);
			second.insertAtBack(value);
	}

	if(!tempfirst.isEmpty())
	{
		do
		{
			tempfirst.removeFromBack(value);
			second.insertAtBack(value);
		}while(!tempfirst.isEmpty());
	}
}

int main()
{

	List<char> listOne;
	List<char> listTwo;
	char c;


	for(c ='a';c <= 'j'; c++)
	{
		listOne.insertAtBack(c);
	}

	listOne.print();

	reverseOrder(listOne,listTwo);
	listTwo.print();

	return 0;
}
