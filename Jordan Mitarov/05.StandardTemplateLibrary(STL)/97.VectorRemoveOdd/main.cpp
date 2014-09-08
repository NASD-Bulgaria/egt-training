#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> enterElementInVector(int,vector<int> &);
vector<int> findOddElementTimes(vector<int> &);
void printVec(vector<int> &);

int main()
{

	int size;

	vector<int> myVec;
	vector<int> myVecTwo;
	cout<<"How number you want enter? ";
	cin>>size;

	myVec = enterElementInVector(size,myVec);
	sort(myVec.begin(),myVec.end());
	myVecTwo = findOddElementTimes(myVec);
	cout<<"The list is: ";
	printVec(myVecTwo);

	return 0;
}

vector<int> enterElementInVector(int size,vector<int> &vecRef)
{
	int num;

	for(int i=0;i<size;i++)
	{
		cout<<"Enter number: ";
		cin>>num;

		vecRef.push_back(num);
	}

	return vecRef;
}

vector<int> findOddElementTimes(vector<int> &vecRef)
{
	vector<int> vecRef2;

	int sequence = 1;
	int element = 0;

	vector<int>::iterator it;
	for(it=vecRef.begin(); it<vecRef.end(); it++)
	{
		if(*(it)==*(it+1))
		{
			sequence++;
			if(sequence > 1)
			{
				element = *(it);
				for(int i=0;i<sequence;i++)
				{
					if(element%2==1)
					{
						vecRef2.push_back(element);
					}
				}
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
