#include <algorithm>
#include <iterator>
#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <stack>
#include <map>
#include <queue>
using namespace std;


void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();

int main()
{
//	task1();
//	task2();
//	task3();
//	task4();
//	task5();
//	task6();
//	task7();
//	task8();


	return 0;
}



void task1()
{
/*	Write a program that reads from the console a
	sequence of positive integer numbers. The
	sequence ends when the number 0 is entered.
	Calculate and print the sum and average of the
	elements of the sequence. Use linked list.*/

	list <int> number;
	int num = 1;
	cout << "Enter positive numbers or 0 for end" << endl;

	while (num != 0)
	{
		cin >> num;
		if (num > 0)
		{
			number.push_back(num);
		}
	}

	list<int>::const_iterator iter ;
	int sum = 0;
	for (iter = number.begin(); iter != number.end(); ++iter)
	{
		sum += *iter;
	}
	cout << "Sum is: " << sum << endl;
	cout << "Average is: " << sum /(double) number.size() << endl;

}

void task2()
{
//	Write a method that finds the longest subsequence
//	of equal numbers in given array.
	vector<int> num (1);
	srand (time(NULL));
	for (int k = 0; k < 30; k++)
	{
		num.push_back( rand()%10);
	}
	cout << "All numbers: " ;
	for (unsigned int var = 0; var < num.size(); ++var)
	{
		cout << num[var] << " ";
	}
	cout << endl;
	int counter, maxSeq = 0, index;
	for (unsigned int i = 0; i < num.size() - 1; ++i)
	{
		counter = 1;
		while (num[i] == num [i+1])
		{
				counter++;
				i++;

		}
		if (counter > maxSeq)
		{

			maxSeq = counter;
			index = i;
			i += counter;
		}
	}
	cout << "Max sequence is:";
	if (maxSeq == 1)
	{
		cout << "There is no sequence of equal numbers!" << endl;
	}
		else
		{
			while(maxSeq > 0)
			{
				cout << num[index] << " ";
				index--;
				maxSeq--;
			}
		}
}

void task3 ()
{
//	Write a program that reads N integers from the
//	console and reverses them using a stack.

	stack< int > intDequeStack;
	int n, number;
	cout << "Enter number of elements: " << endl;
	cin >> n;
	cout << "Enter " << n << " elements";
	for (int i = 0; i < n; i++)
	{
		cin >> number;
		intDequeStack.push(number);
	}
	while (!intDequeStack.empty())
	{
		cout << intDequeStack.top() << " " ;
		intDequeStack.pop();
	}


}

void task4()
{
/*	We are given the following sequence:
	S1 = N;
	S2 = S1 + 1;
	S3 = 2*S1 + 1;
	S4 = S1 + 2;
	S5 = S2 + 1;
	S6 = 2*S2 + 1;
	S7 = S2 + 2;
	...
	Write a program to print its first 100 elements for
	given N. Use the queue class.
	Example: N=2
	Sequence: 2, 3, 5, 4, 4, 7, 5, 6, 11, 7, 5, 9, 6, ...*/

	queue < int > values;
	int number;

	cout << "Enter number: ";
	cin >> number;
	values.push(number);

	for(int i = 0; i < 100; ++i)
	{
		values.push( values.front() + 1 );
		values.push( 2*values.front() + 1 );
		values.push( values.front() + 2 );
		cout << values.front()<<' ';
		values.pop();
	}
}

void task5()
{
//	Write a program that reads a sequence of integers ending
//	with 0 and sorts them in an increasing order. Use linked
//	list.

	list <int> numbers;
	int n;
	cout << "Enter 1 for end" << endl;
	while (n != 1)
	{
		cout << "Enter number: ";
		cin >> n;
		if (n % 10 == 0)
		{
			numbers.push_back(n);
		}
	}
	numbers.sort();
	cout << "After sort: ";

	if (numbers.empty())
	{
		cout << "List is empty.";
	}
	else
	{
		ostream_iterator <int> output (cout, " ");
		copy (numbers.begin(), numbers.end(), output);
	}
}


void task6 ()
{
//	Write a program that finds in a given array of integers how
//	many times each of them presents.
//	Example: array = {3, 4, 4, 2, 3, 3, 4, 3, 2}
//	2  2 times
//	3  4 times
//	4  3 times

	vector <int> num;
	int n = 1;
	cout << "Enter number: ";
	while (n != 0)
	{
		cin >> n;
		num.push_back(n);
	}
	map <int, int > numbers;
	map<int,int>::iterator it;

	for (unsigned int i = 0; i < num.size(); i++)
	{
		it = numbers.find(num[i]);
		if (it == numbers.end())
		{
			numbers.insert(pair <int,int> (num[i], 1));
		}
		else
		{
			it->second++;
		}
	}
	for (it = numbers.begin(); it != numbers.end(); it++)
	{
		cout << it->first << " -> " << it->second << endl;
	}
}


void task7()
{
//	Write a program that removes from a given
//	sequence all negative numbers.


	vector <int> num;
	int n;
	cout << "Enter number: ";
	while (n != 0)
	{
		cin >> n;
		num.push_back(n);
	}
	vector<int> numbers;
	for (unsigned int i = 0; i < num.size(); ++i)
	{
		if (num[i] >= 0)
		{
			numbers.push_back(num[i]);
		}
	}
	cout << "All positive numbers are :" << endl;
	for (unsigned int i = 0; i < numbers.size(); ++i)
	{
		cout << numbers[i] << " ";
	}

}


void task8()
{
//	Write a program that removes from a given
//	sequence all the numbers that present in it odd
//	number of times. Example:
//	{4, 2, 2, 5, 2, 3, 2, 3, 1, 5, 2}  {5, 3, 3, 5}

	vector <int> num;
	int n;
	cout << "Enter number: ";
	while (n != 0)
	{
		cin >> n;
		num.push_back(n);
	}
	vector<int> numbers;
	for (unsigned int i = 0; i < num.size(); ++i)
	{
		if (num[i] % 2 != 0)
		{
			numbers.push_back(num[i]);
		}
	}
	cout << "All even numbers are :" << endl;
	for (unsigned int i = 0; i < numbers.size(); ++i)
	{
		cout << numbers[i] << " ";
	}

}
