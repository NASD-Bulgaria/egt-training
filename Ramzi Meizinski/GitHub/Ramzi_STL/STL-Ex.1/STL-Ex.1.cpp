//Write a program that reads from the console a
//sequence of positive integer numbers. The
//sequence ends when the number 0 is entered.
//Calculate and print the sum and average of the
//elements of the sequence. Use linked list.

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {

	list<int> numbers;
	int x;
	do{
	cout << "Enter integer: ";
	cin >> x;
	if(x == 0)
	{
		break;
	}
	numbers.push_back(x);
	}while(x!=0);

	int sum = accumulate(numbers.begin(),numbers.end(),x);
	double avg =static_cast<double>( sum) /static_cast<double> (numbers.size());
	cout << "The sum is: " << sum << endl;
	cout << "The averrage is: " << avg << endl;
	ostream_iterator<int> outPut(cout, " ");
	copy(numbers.begin(),numbers.end(),outPut);


	return 0;
}
