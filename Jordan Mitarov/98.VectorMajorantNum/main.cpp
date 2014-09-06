/*9. By definition the majorant of an array is a value that
occur in the least half of the elements of the array.
Write a program to find the majorant of given array
(if any). Example:
{2, 2, 3, 3, 2, 3, 4, 3, 3} -> 3*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> enterElementInVector(int,vector<int> &);
vector<int> findMajorElements(vector<int> &);
void printVec(vector<int> &);

int main()
{

	int sizeVector;

	vector<int> myVec;
	vector<int> myVecTwo;
	cout<<"How number you want enter? ";
	cin>>sizeVector;

	myVec = enterElementInVector(sizeVector,myVec);
	sort(myVec.begin(),myVec.end());
	myVecTwo = findMajorElements(myVec);
	cout<<"The list of Major element is: ";
	printVec(myVecTwo);

	return 0;
}

vector<int> enterElementInVector(int sizeVector,vector<int> &vecRef)
{
	int num;

	for(int i=0;i<sizeVector;i++)
	{
		cout<<"Enter number: ";
		cin>>num;

		vecRef.push_back(num);
	}

	return vecRef;
}

vector<int> findMajorElements(vector<int> &vecRef)
{
	vector<int> vecRef2;

	int sequence = 1;
	int element = 0;
	int sizeHalf = vecRef.size() / 2;
 	vector<int>::iterator it;
	for(it=vecRef.begin(); it<vecRef.end(); it++)
	{
		if(*(it)==*(it+1))
		{
			sequence++;
			if(sequence == sizeHalf)
			{

				element = *(it);
				vecRef2.push_back(element);
			}
		}
		else
		{
			sequence = 1;
		}
	}


	return vecRef2;
}

void printVec(vector<int> &vecRef)
{
	for(unsigned int i = 0;i<vecRef.size();i++)
	{
		cout<<vecRef[i]<<' ';
	}
}
