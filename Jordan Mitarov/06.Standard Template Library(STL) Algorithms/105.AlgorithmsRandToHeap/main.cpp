/*6. Convert a random sequence of numbers to a heap.
Convert the heap to a sorted sequence and back to a
heap.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime> //for time(0)
#include <cstdlib>
using namespace std;

int randNum ()
{
	int i = rand()%50;
	return i;
}

int main()
{
	srand ( unsigned ( time(0) ));

	vector<int> vectorOne(10);
	ostream_iterator< int > output( cout, " " );


	generate( vectorOne.begin(), vectorOne.end(), randNum );
	cout<<"\nVector before make_heap: ";
	copy(vectorOne.begin(),vectorOne.end(),output);

	make_heap(vectorOne.begin(),vectorOne.end());
	cout<<"\nVector after make_heap: ";
	copy(vectorOne.begin(),vectorOne.end(),output);

	sort_heap(vectorOne.begin(),vectorOne.end());
	cout<<"\nVector after sort_heap: ";
	copy(vectorOne.begin(),vectorOne.end(),output);
/*	sort(vectorOne.begin(),vectorOne.end());
	reverse(vectorOne.begin(),vectorOne.end());

	copy(vectorOne.begin(),vectorOne.end(),output);*/

	for ( unsigned int j = 0; j < vectorOne.size(); j++ )
	{
		cout << "\nVector after " << vectorOne[ 0 ] << " popped from heap\n";
		std::pop_heap( vectorOne.begin(), vectorOne.end() - j );
		std::copy( vectorOne.begin(), vectorOne.end(), output );
	} // end for

	make_heap(vectorOne.begin(),vectorOne.end());
	cout<<endl;
	copy(vectorOne.begin(),vectorOne.end(),output);

	return 0;
}
