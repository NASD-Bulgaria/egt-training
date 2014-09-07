//Write a program that finds the longest subsequence of
//greater values in array.

#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

typedef multiset<int, less<int> > Ims;

int main() {
	const int SIZE = 20;
	int arr[SIZE] =
			{ 2, 1, 3, 3, 6, 6, 5, 5, 5, 8, 7, 4, 1, 1, 1, 1, 9, 6, 5, 4 };
	cout << "Array is:" << endl;
	for (int i =0; i<SIZE;i++)
	{
		cout << arr[i] << " ";
	}
	Ims greaterSub;
	greaterSub.insert(arr, arr + SIZE);
	Ims::iterator it;
	int sum = 0;
	for (it = greaterSub.begin(); it != greaterSub.end(); it++) {
		sum += *it;
	}
	int avg = sum / greaterSub.size();
	it = greaterSub.begin();
	unsigned int max = 0;
	int numb;
	while (it != greaterSub.end()) {
		if (*it > avg) {
			if (max < greaterSub.count(*it)) {
				max = greaterSub.count(*it);
				numb = *it;
			}
		}
		it = greaterSub.upper_bound(*it);
	}
	cout << "\nAverrage is: " << avg << endl;
	cout << "The longest subsequence of greater values in array is:\n";
	cout << numb << " -> " << max << " times." << endl;
	return 0;
}
