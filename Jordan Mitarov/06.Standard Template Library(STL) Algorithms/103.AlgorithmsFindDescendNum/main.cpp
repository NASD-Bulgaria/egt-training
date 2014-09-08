/*
4. Write a program that generates a random number
sequence and finds the first 3 elements in descending
order.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>
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

	generate(vectorOne.begin(),vectorOne.end(),randNum);
	copy(vectorOne.begin(),vectorOne.end(),output);
	cout<<endl;

		if(vectorOne[0] > vectorOne[1] && vectorOne[1] > vectorOne[2])
		{
			cout<<"First three num in descending order: "<<vectorOne[0] <<" "<<vectorOne[1] <<" "<<vectorOne[2];
		}

		else
		{
			cout<<"First three numbers is not in descending order";
		}

	//copy(vectorOne.begin(),vectorOne.end(),output);


	return 0;
}
