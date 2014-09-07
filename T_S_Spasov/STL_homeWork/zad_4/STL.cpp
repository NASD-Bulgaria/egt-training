//Write a program that reads N integers from the
//console and reverses them using a stack

#include <iostream>
#include <queue> // list class-template definition
#include <algorithm> // copy algorithm
#include <iterator> // ostream_iterator
using namespace std;
#define SIZE 5



int main()
{

	queue < int > values;
   int number;

	   cout << "Enter number ";
	   cin >> number;
	   values.push(number);

for(int i = 0; i < 100; ++i){
values.push( values.front() + 1 );
values.push( 2*values.front() + 1 );
values.push( values.front() + 2 );
cout << values.front()<<' ';
values.pop();


}
//


   return 0;
} // end main


