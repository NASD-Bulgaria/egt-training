//1. Write a program that reads from the console a
//sequence of positive integer numbers. The
//sequence ends when the number 0 is entered.
//Calculate and print the sum and average of the
//elements of the sequence. Use linked list.

#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main() {
	list<int> numbers;
	int number;
	cout << "Enter a positive integer: ";
	cin >> number;

	while (number != 0) {

		numbers.push_back(number);
		cout << "Enter a positive integer: ";
		cin >> number;
	}
	int sum;
	for (list<int>::iterator i = numbers.begin() ; i != numbers.end() ; i ++){
		sum += *i;
	}
	double average;
	average = (double)sum / numbers.size();

	cout << "The sum is : " << sum << endl;
	cout << "The average is : " << average << endl;
	return 0;
}
