#include <iostream>
#include<map>
#include<algorithm>
#include <iterator>
#include<vector>
using namespace std;

int main() {
	int arr[10]={1,1,5,1,5,3,1,6,5,5};
	int k;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				k=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=k;
			}
		}
	}
	map<int,int>odd;
	vector<int>oddNums;
	int currentNumber = arr[0], currentMax = 1;
	for(int i = 1; i < 10; i++)

	    {

	        if(arr[i] == currentNumber)

	        { currentMax++;

	        }

	        else

	        {
	        	if(currentMax%2==0){
	        	odd.insert(std::map<int, int>::value_type(currentNumber, currentMax));
	        	oddNums.push_back(currentNumber);

	        	}

	            currentNumber = arr[i];
	            currentMax=1;
	            if(currentNumber==arr[9])
	            {

	            	for(int j=i+1;j<10;j++)
	            	{
	            		currentMax++;
	            	}
	            	if(currentMax%2==0)
	            	{
	            	odd.insert(std::map<int, int>::value_type(currentNumber, currentMax));
	            	oddNums.push_back(currentNumber);
	            	}
	            }


	        }


	    }
	map<int, int>::iterator p;
		for ( p = odd.begin(); p!=odd.end(); ++p)
		cout<< p->first<< ": "<< p->second<< '\n'<<endl;
	vector<int>::iterator iter;
	for(iter=oddNums.begin();iter!=oddNums.end();++iter)
	{
		cout<<*iter<<" ";
	}

	return 0;
}

