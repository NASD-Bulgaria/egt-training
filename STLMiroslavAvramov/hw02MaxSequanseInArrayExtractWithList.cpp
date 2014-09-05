/*
 2. Write a method that finds the longest subsequence
 of equal numbers in given array. Use linked list.
 */
#include<iostream>
using namespace std;

#include <list>
#include <iterator>
#include <algorithm>

void printMaxSquance( list<int> res);
list<int> findLongestSubSequanceInList(int arr[],int size);

//template<typename T> T findLongestSubSequanceInList(const std::list<T> &listRef) {

//	int sequence = 1;
//	int maxSequence = 1;
//	T value = 0;
//	for (std::list<int>::const_iterator it = listRef.begin(); it != listRef.end(); ++it)
//		//cout << *it + 1;
//		if (*it == (*it + 1)) {
//			cout << *it;
//			sequence++;
//			if (sequence > maxSequence) {
//				maxSequence = sequence;
//				value = *it;
//				cout << sequence;
//			}
//		} else {
//			sequence = 1;
//		}
//
//	return value;
//}
int main() {

//	int value;
//	list<int> c;
//	while (value != 0) {
//		cout << "Enter digit : " << endl;
//		cin >> value;
//		c.push_back(value);
//	}
//	cout << findLongestSubSequanceInList(c);


	int const size = 10;
	int array[size] = { 2, 1, 1, 2, 3, 3, 2, 2, 2, 1 };

	list<int> result = findLongestSubSequanceInList(array, size);

	printMaxSquance(result);

//	for (int i = 0; i < maxSequence; i++) {
//		cout << seq[i] << " ";
//	}

}

list<int> findLongestSubSequanceInList(int arr[],int size){
	int value = 0;
	int sequence = 1;
	int maxSequence = 1;

	for (int i = 0; i < size; i++) {
		if (arr[i] == arr[i + 1]) {
			sequence++;
			if (sequence > maxSequence) {
				maxSequence = sequence;
				value = arr[i];
			}
		} else {
			sequence = 1;
		}
	}

	list <int> seq;

	for (int i = 0; i < maxSequence; i++) {
		seq.push_back(value);
	}
	return seq;
}

void printMaxSquance( list<int> res){
	ostream_iterator<int> output(cout, " ");
	copy( res.begin(), res.end(), output );
}
