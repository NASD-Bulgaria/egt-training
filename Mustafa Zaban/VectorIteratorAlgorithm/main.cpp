#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

bool greather9( int );

int main ()
{
	const int SIZE = 10;
	int a[SIZE] = {10, 23, 10, 42, 15, 10, 7, 18, 9, 1};
	int b[SIZE] = {9, 11, 3, 36, 15, 2, 8, 9, 18, 23};
	ostream_iterator< int > output(cout, " ");
	vector< int > v(a, a+SIZE); //copy of "a" from the begin to the end
	vector< int > g(b, b+SIZE);
	vector< int > product(10);
	vector< int >::iterator iter;

	/*make_heap(v.begin(), v.end());
	cout << "\n\nShow heap:\n\n";
	copy(v.begin(), v.end(), output);

	sort_heap(v.begin(), v.end());
	cout << "\n\nShow the sorted heap:\n\n";
	copy(v.begin(), v.end(), output);*/



	sort(v.begin(), v.end());
	sort(g.begin(), g.end());
	cout << endl;
	//iter = set_symmetric_difference (v.begin(), v.end(), g.begin(), g.end(), product.begin());
	//product.resize(iter-product.begin());
	//for (iter = product.begin(); iter != product.end(); ++iter)
	 //   {
	   //  	cout << *iter << " ";
    	//}



	cout << "\nThe vector before removing all 10s:\n";
	copy(v.begin(),v.end(), output); //show the vector contents
	
	random_shuffle(v.begin(), v.end()); //reorder the vector elements in random order

	cout << "\n\nThe vector after shuflle reorder:\n\n";
	copy(v.begin(), v.end(), output);

	cout << "\n\nThe minimum element in vector is: " << *(min_element(v.begin(),v.end())) << endl; //minimum element function

	cout << "\n\nSorted vector is:\n\n";
	sort(v.begin(), v.end()); //sort in ascending oredr in your vector
	copy(v.begin(), v.end(), output);

	cout << "\n\n";
	vector< int >::iterator testIterator; // pravish tozi iterator za da napravish now stream s tochnata broyka elementi
	testIterator = unique(v.begin(), v.end()); //namira vsichki unikalni i 

	cout << "\nUnique elements in vector:\n";
	copy(v.begin(), testIterator, output);


    cout << "\n\nThe vector without 10s:\n";
	newLastElement = remove(v.begin(), v.end(), 10);
	copy(v.begin(),newLastElement,output);

	cout << endl;
	return 0;
}
