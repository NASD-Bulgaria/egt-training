#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main (){

	cout << "Enter random numbers, enter 0 for end:" << endl;
	vector<int> intVector;

	istream_iterator<int> inputInt( cin );
	
	while (*inputInt != 0)
	{
		intVector.push_back(*inputInt);
		++inputInt;
	}

	

	int sizeOfVector = intVector.size();
	int tempValue = 0;
	int sumOfSeq = 0;

	for (int i = 0; i < sizeOfVector; i++)
	{
		tempValue += intVector.at(i);
		sumOfSeq = tempValue;
	}

	cout << endl;
	ostream_iterator<int> outputInt ( cout );
	cout << "The average of your sequence is: ";
	*outputInt = tempValue/sizeOfVector;
	cout << endl;
	cout << endl;

	cout << "The sum of your sequence is: ";
	++outputInt;
	*outputInt = sumOfSeq;

	cout << endl;
	cout << endl;
	
	


	return 0;
}

