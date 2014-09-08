/*Write a program that inserts 25 random integers
from 0 to 100 in order in a linked list object. The
program should calculate the sum of the elements
and the floating-point average of the elements .*/

#include <iostream>
#include <stdlib.h> //rand / srand
#include <time.h>
using namespace std;

#include "List.h"

int sumList(List<int> &listRef)
{
	List<int> temp(listRef);
	int sum = 0;
	int value;

	//until temp is empty
	while(!temp.isEmpty())
	{
		temp.removeFromFront(value);
		sum +=value;
	}

	return sum;
}

double averageList(List<int> &listRef)
{
	List<int> temp(listRef);
	int sum = 0;
	int value;
	int count = 0;


	//go through opy of listRef
	while(!temp.isEmpty())
	{
		temp.removeFromFront(value);
		count++;
		sum += value;
	}

	return static_cast<double> (sum) / (count);
}

int main()
{
	srand(time(0));

	List<int> list;

	for(int i=1;i<=25;i++)
	{
		list.insertInOrder(rand() % 101);
	}

	list.print();

	int sum = sumList(list);
	double averageSum = averageList(list);

	cout<<"The sum of element is: "<<sum<<endl;
	cout<<"The sum of average is: "<<averageSum<<endl;


	return 0;
}
