/*6. Convert a random sequence of numbers to a heap.
 Convert the heap to a sorted sequence and back to a
 heap.*/
#include <iostream>
using namespace std;

#include <algorithm> // algorithm definitions
#include <numeric> // accumulate is defined here
#include <vector>
#include <iterator>
#include <ctime>
#include <cstdlib>

int main() {
	srand(time(0));
	const int SIZE = 10;
	int a1[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::vector<int> v(a1, a1 + SIZE); // copy of a1
	std::ostream_iterator<int> output(cout, " ");

	std::random_shuffle(v.begin(), v.end()); // shuffle elements of v
	cout << "\nVector v after random_shuffle: ";
	std::copy(v.begin(), v.end(), output);

	make_heap(v.begin(), v.end());
	cout << "\nVector after make_heap: ";
	copy(v.begin(), v.end(), output);

	std::pop_heap(v.begin(), v.end());
	v.pop_back();
	std::cout << "max heap after pop : " << v.front() << '\n';

	std::sort_heap(v.begin(), v.end());

	std::cout << "final sorted range :";
	for (unsigned i = 0; i < v.size(); i++)
		std::cout << ' ' << v[i];

	std::cout << '\n';

	return 0;
}
