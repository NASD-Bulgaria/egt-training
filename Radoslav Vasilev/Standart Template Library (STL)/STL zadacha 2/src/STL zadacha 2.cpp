//============================================================================
// Name        : STL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
template <typename T>
T longestSequence(vector<T>);
int main()
{
	vector< int > values;
	values.push_back(2);
	values.push_back(2);
	values.push_back(3);
	values.push_back(5);
	values.push_back(7);
	values.push_back(7);
	values.push_back(7);
	values.push_back(7);
	values.push_back(7);
	values.push_back(1);
	cout<<longestSequence(values)<<endl;
	return 0;
}

template <typename T>
T longestSequence(vector<T>array)
{
    T currentNumber = array[0];
    T currentMax = 1;
    T longestMax = 1;
    for(size_t i = 1; i < array.size(); i++)
    {
        if(array[i] == currentNumber)
        {
        	currentMax++;
        }
        else
        {
            currentNumber = array[i];
            if(currentMax > longestMax)
            {
                longestMax = currentMax;
                currentMax = 1;
            }
        }
    }
    return longestMax;
}
