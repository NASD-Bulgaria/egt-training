/*2.Write a method that finds the longest subsequence
of equal numbers in given array. Use linked list.*/

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

list<int> searchMaxSequence(int [],int);
void printMaxSequence(list<int> &);
int main()
{
	const int size = 15;

	int maxS[size];
	list<int> maxSequencRes;
	cout<<"Enter the numbers: \n";
	for(int i=0; i<size; i++)
	{
		cout<<"arr["<<i+1<<"] = ";
		cin>>maxS[i];
	}

	maxSequencRes = searchMaxSequence(maxS,size);
	cout<<"The list with max Sequence is: ";
	printMaxSequence(maxSequencRes);

	return 0;
}

list<int> searchMaxSequence(int maxS[],int s)
{
	int sequence = 1;
	int maxSequence = 0;
	int element = 0;
	list<int> maxSequ;

	for(int i = 0; i < s; i++)
	{
		if(maxS[i]==maxS[i+1])
		{
			sequence++;
			if(sequence > maxSequence)
			{
				maxSequence = sequence;
				element = maxS[i];
			}
		}
		else
		{
			sequence = 1;
		}
	}

	for(int i=0;i<maxSequence;i++)
	{
		maxSequ.push_back(element);
	}

	return maxSequ;
}

void printMaxSequence(list<int> &maxSequence)
{
	ostream_iterator< int > output( cout, " " );
	copy( maxSequence.begin(), maxSequence.end(), output );
}
