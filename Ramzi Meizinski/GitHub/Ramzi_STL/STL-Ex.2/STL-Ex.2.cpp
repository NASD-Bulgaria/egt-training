//Write a method that finds the longest subsequence
//of equal numbers in given array. Use linked list.

#include <iostream>
#include <list>
#include <iterator>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
	const int SIZE = 10;
	int arr[SIZE] = {3,2,2,3,3,3,3,3,4,6};

	list<int> numbers(arr,arr + SIZE);
//	ostream_iterator<int> output(cout," ");
//	copy(numbers.begin(),numbers.end(),output);
	list<int>::iterator it;
	it = numbers.begin();
	int num = *it;
	int count =0;
	int max=0;
	for (it = numbers.begin(); it != numbers.end(); it++) {

		if (*it == num) {
			count++;
		} else {
			count = 1;
		}
		if (count > max) {
			max = count;
		}
		num = *it;
	}

	cout << "Max is: " << max << endl;
	return 0;
}
