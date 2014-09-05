#include <iostream>
#include<map>
#include<algorithm>
#include <iterator>
using namespace std;

int main() {
	int arr[10]={1,3,5,1,5,3,1,1,3,5};
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
	map<int,int>integers;
	int currentNumber = arr[0], currentMax = 1;
	for(int i = 1; i < 10; i++)

	    {

	        if(arr[i] == currentNumber)

	        { currentMax++;

	        }

	        else

	        {
	        	integers.insert(std::map<int, int>::value_type(currentNumber, currentMax));
	        		        cout<<currentNumber<<" "<<currentMax<<endl;

	            currentNumber = arr[i];
	            currentMax=1;
	            if(currentNumber==arr[9])
	            {

	            	for(int j=i+1;j<10;j++)
	            	{
	            		currentMax++;
	            	}
	            	integers.insert(std::map<int, int>::value_type(currentNumber, currentMax));

	            }


	        }


	    }
	map<int, int>::iterator p;
		for ( p = integers.begin(); p!=integers.end(); ++p)
		cout<< p->first<< ": "<< p->second<< '\n'<<endl;
	return 0;
}

