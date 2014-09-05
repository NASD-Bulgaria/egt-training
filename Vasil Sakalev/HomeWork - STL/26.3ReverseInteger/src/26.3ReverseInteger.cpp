//3.Write a program that reads N integers from the
//console and reverses them using a stack.

#include <iostream>
#include <stack>
using namespace std;

template< typename T > void pushElements( T &stackRef );
template< typename T > void popElements( T &stackRef );

int main()
{
	stack< int > numbers;

	pushElements(numbers);

	cout << "\nReverse elements are:" << endl;
	popElements(numbers);

	return 0;
}

template< typename T > void pushElements( T &stackRef )
{
   cout << "How many element do you want to enter: ";
   int size;
   cin >> size;
   for ( int i = 0; i < size; i++ )
   {
	  int element;
	  cout << "Element[" << i <<"]= ";
	  cin >> element;
      stackRef.push( element );
   }
}

template< typename T > void popElements( T &stackRef )
{
   while ( !stackRef.empty() )
   {
      cout << stackRef.top() << ' ';
      stackRef.pop();
   }
}
