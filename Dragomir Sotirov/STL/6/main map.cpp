#include <iostream>
#include <map>
#include <set>
#include <iterator>

using namespace std;

int main()
{
int array[9] = {3, 4, 4, 2, 3, 3, 4, 3, 2};
typedef multiset< int, less< int > > Ims;
Ims intMultiset;
ostream_iterator< int > output( cout, " " );
intMultiset.insert( array, array + 9 );
cout << "Inserting array in Multiset...\n";
copy( intMultiset.begin(), intMultiset.end(), output );
cout<<endl;
cout << "2 -> " << intMultiset.count(2) << " times\n";
cout << "3 -> " << intMultiset.count(3) << " times\n";
cout << "4 -> " << intMultiset.count(4) << " times\n";

 return 0;
}
