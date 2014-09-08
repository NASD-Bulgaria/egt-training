/*3.Write a program that generates a random number
sequence and sorts it in descending order.*/

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

	sort(vectorOne.begin(),vectorOne.end());
	reverse(vectorOne.begin(),vectorOne.end());

	copy(vectorOne.begin(),vectorOne.end(),output);

	return 0;
}
