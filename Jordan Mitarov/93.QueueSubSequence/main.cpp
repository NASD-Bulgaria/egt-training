/*4. We are given the following sequence:
S1 = N;
S2 = S1 + 1;
S3 = 2*S1 + 1;
S4 = S1 + 2;
S5 = S2 + 1;
S6 = 2*S2 + 1;
S7 = S2 + 2;
...
Write a program to print its first 100 elements for
given N. Use the queue class.
Example: N=2
Sequence: 2, 3, 5, 4, 4, 7, 5, 6, 11, 7, 5, 9, 6, ...*/

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
void sequence(queue<T> );

int main()
{
	queue<int> values;

	sequence(values);

	return 0;
}

template <typename T>
void sequence(queue<T> refQueue)
{
	int N;

	cout<<"Enter number: ";
	cin>>N;
	refQueue.push(N);

	for(int i=0;i<100;++i)
	{
		refQueue.push(refQueue.front()+1);
		refQueue.push(2*refQueue.front()+1);
		refQueue.push(refQueue.front() + 2);
		cout<<refQueue.front()<<' ';
		refQueue.pop();
	}
}
