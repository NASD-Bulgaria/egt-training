/*6. Write a program that finds in a given array of integers how
many times each of them presents.
Example: array = {3, 4, 4, 2, 3, 3, 4, 3, 2}
2 -> 2 times
3 -> 4 times
4 -> 3 times*/
#include <iostream>
#include <map>
using namespace std;

void printMap(map<int,int> &);

int main() {

	    std::map<int , int> countNums;
	    printMap(countNums);


	return 0;
}

void printMap(map<int,int> &countNumbers)
{
	int size;
	int arr[size];
	cout<<"How numbers you enter?  ";
	cin>>size;

	map<int, int>::const_iterator it;

	for(int i=0;i<size;i++)
	{
		cout<<"arr["<<i+1<<"] = ";
		cin>>arr[i];
	}

	for (int i = 0; i <  size; i++)
	{
		if(countNumbers.find(arr[i]) != countNumbers.end())
		{
			++countNumbers[arr[i]];
		}
		else
		{
			countNumbers.insert(std::pair<int,int>(arr[i], 1));
		}
	}
	for (  it = countNumbers.begin(); it != countNumbers.end(); ++it )
	{
		cout << it->first << " ->"<<" " << it->second <<" times"<< '\n';
	}
}
