/*3. Write a program that reads N integers from the
console and reverses them using a stack.*/

#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

template <typename T>
void pushElement(stack<T> &);
template <typename T>
void popElement(stack<T> &);

int main()
{
	stack< int> intVectorStack;

	cout<<"The elements is: ";
	pushElement(intVectorStack);
	cout<<"\nThe elements in reverse order is: ";
	popElement(intVectorStack);


	return 0;
}

template <typename T>
void pushElement(stack<T> &stackRef)
{
	int num;
	const int size = 5;

	for(int i=0;i<size;i++)
	{
		cin>>num;
		stackRef.push(num);
	}
}

template <typename T>
void popElement(stack<T> &stackRef)
{
	while(!stackRef.empty())
	{
		cout<<stackRef.top()<<' ';
		stackRef.pop();
	}
}
