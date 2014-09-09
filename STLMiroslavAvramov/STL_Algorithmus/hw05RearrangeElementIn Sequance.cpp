/*5. Make a function that rearranges the order of
 elements in a sequence so that elements that are less
 than or equal to the nth element are placed before
 the nth element. Elements in this group are sorted.
 Other elements are placed after the nth element and
 are not sorted.*/
#include <iostream>
using namespace std;

#include <algorithm> // algorithm definitions
#include <vector> // vector class-template definition
#include <iterator>

void rearrange(int arr[], int size, int n);

int main() {
	const int SIZE = 10;
	int a[SIZE] = { 21, 2, 17, 5, 16, 8, 13, 11, 20, 7 };
//	std::vector<int> v(a, a + SIZE); // copy of a
//	std::vector<int> vRemove(a, a + SIZE); // copy of a
//	vector<int> res(10);
//	std::ostream_iterator<int> output(cout, " ");

	cout << "Enter N position to sort: ";
	int n;
	cin >> n;
	rearrange(a, SIZE, n);

//	int value = v[n];

//	for (unsigned int i = 0; i < vRemove.size(); ++i) {
//		if (vRemove[i] > value) {
//			std::remove( vRemove.begin(), vRemove.end(), v[i] );
//		}
//	}

//	for (int i = 0; i < n; ++i) {
//		if (v[i] < value && v[n + i] > value) {
//			std::swap(v[i], v[n + i]);
//		}
//	}

//std::sort( v.begin(), v.end() - n );
//	std::copy(res.begin(), res.end(), output); // display output vector

	return 0;
}

void rearrange(int arr[], int size, int n) {
	vector<int> less;
	vector<int> greater;
	for (int j = 0; j < size; ++j) {
		if (arr[j] < n) {
			less.push_back(arr[j]);
		} else {
			greater.push_back(arr[j]);
		}
	}
	sort(less.begin(), less.end());
	vector<int> rearrenge(less.size() + greater.size());

	merge(less.begin(), less.end(), greater.begin(), greater.end(),
				rearrenge.begin());

		cout << "The result is: ";

//	for (int i = 0; i < rearrenge.size(); ++i) {
//		if (i < less.size()) {
//			rearrenge.push_back(less[i]);
//		} else {
//			rearrenge.push_back(greater[i]);
//		}
//	}

	for (unsigned int i = 0; i < rearrenge.size(); i++) {
		cout << rearrange[i] << " ";
	}

//	std::ostream_iterator<int> output(cout, " ");
//	std::copy(rearrenge.begin(), rearrenge.end(), output); // display output vector
}

