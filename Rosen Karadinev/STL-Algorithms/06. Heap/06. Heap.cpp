#include <iostream>
#include <set>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{

srand(time(0));

vector<int> numbers(10);

cout << "Vector :" << endl;

for (int i = 0; i < 10; i++)
{
	numbers[i] = 1 + rand() % 10;
	cout << numbers[i]<< " ";
}

make_heap(numbers.begin(), numbers.end());

cout <<endl<< "Numbers in Heap Vector are:"<<endl;

for (int i = 0; i < 10; i++)
{
	cout << numbers[i]<< " ";
}

sort_heap(numbers.begin(), numbers.end());

cout <<endl<< "Sorted Heap Vector are:"<<endl;

for (int i = 0; i < 10; i++)
{
	cout << numbers[i]<< " ";
}

return 0;
}
