//============================================================================
// Name        : STL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <iterator>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

void linkedListNumbers(istream_iterator<int> &);
void longestSequence(istream_iterator<int> &);
void reverseSequence(istream_iterator<int> &);
void queueSequence();
void sequenseSort(istream_iterator<int> &);


int main()
{
	cout << "Enter sequence of numbers(enter 0 to end): ";
	istream_iterator<int> inputInt(cin);



	sequenseSort(inputInt);


	return 0;
}

void sequenseSort(istream_iterator<int> &input)
{
	list<int> sequense;

	while (*input != 0)
	{
		sequense.push_back(*input);
		input++;
	}

	sequense.sort();

	for (list<int>::iterator it = sequense.begin(); it != sequense.end(); it++)
	{
		cout << *it<<", ";
	}

}

void queueSequence()
{
	int n;
	cout << "Please enter N!: ";
	cin >> n;

	queue<int> values;

	values.push(n);
	int a;
	int b;
	int c;

	cout <<n <<", ";

	for (int i = 0; i < 33; i++)
	{
		n = values.front();
		a = n + 1;
		b = 2 * n + 1;
		c = n + 2;
		values.push(a);
		values.push(b);
		values.push(c);
		values.pop();
		cout<<a <<", "<<b<<", "<<c<<", ";
	}



}

void reverseSequence(istream_iterator<int> &input)
{
	stack<int> reverse;

	while(*input != 0)
	{
		reverse.push(*input);
		input++;
	}

	while(!reverse.empty())
	{
		cout<<reverse.top()<<", ";
		reverse.pop();
	}


}

void linkedListNumbers(istream_iterator<int> &input)
{
	list<int> numbers;
	int sum = 0;
	int counter = 0;
	double avg = 0;

	while(*input != 0)
	{
		numbers.push_back(*input);
		input++;
		counter++;
	}

	for(list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		sum += *it;
	}

	avg = sum / counter;

	cout<< "Sum: "<< sum << endl
		<<"Average: "<< avg << endl;
}

void longestSequence(istream_iterator<int> &input)
{
	list<int> sequence;

	while(*input != 0)
	{
		sequence.push_back(*input);
		input++;
	}

	int counter = 0;
	int lSequence = 0;
	int temp;
	int seqNum;

	list<int>::iterator it = sequence.begin();

	while(it != sequence.end())
	{
		temp = *it;

		while((temp == *it) && (it != sequence.end()))
		{
			counter++;
			it++;
		}

		if (counter > lSequence)
		{
			lSequence = counter;
			seqNum = temp;
		}

		counter = 0;
	}

	cout << "Number: "<<seqNum << " Sequence: "<<lSequence <<endl;
}
