#include <iostream>
using namespace std;


template<typename T>
void printArray(const T *array, int count, int lowSubscript, int highSubscript)
{
	if((lowSubscript < 0) ||( highSubscript > count && highSubscript <= lowSubscript))
	{
		cout << "range";
	}
	else
	{
		for(int i = lowSubscript; i < highSubscript; i++)
		{
			cout << array[ i ] << " ";
		}
	}


	cout << endl;

}

int main()
{

	   const int aCount = 5; // size of array a
	   const int bCount = 7; // size of array b
	   const int cCount = 6; // size of array c

	   int a[ aCount ] = { 1, 2, 3, 4, 5 };
	   double b[ bCount ] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
	   char c[ cCount ] = "HELLO";

	   int lowSubscript;
	   int highSubscript;
	   cout << "Enter lowSubscript: ";
	   cin >> lowSubscript;

	   cout << "Enter highSubscript: ";
	   cin >> highSubscript;

	   cout << "Array a contains:" << endl;

	   printArray( a, aCount, lowSubscript, highSubscript);

	   cout << "Array b contains:" << endl;

	   // call double function-template specialization
	   printArray( b, bCount, lowSubscript, highSubscript  );

	   cout << "Array c contains:" << endl;

	   // call character function-template specialization
	   printArray( c, cCount, lowSubscript, highSubscript  );

	   return 0;

	return 0;
}
