#include <string>
#include<iostream>
using namespace std;

void output(const string *, const int);
void quickSort(string[], int, int);
int partition(string[], int, int);

int main()
{
	const int SIZE = 19;

	string animals[] =
	{ "Macaw", "Lion", "Tiger", "Bear", "Toucan", "Zebra", "Puma", "Cat", "Yak",
			"Boar", "Fox", "Ferret", "Crocodile", "Alligator", "Elk", "Ox",
			"Horse", "Eagle", "Hawk" };

	cout << "before:";
	output(animals, SIZE);
	quickSort(animals, 0, SIZE);

	cout << "\nafter:";
	output(animals, SIZE);
}

void output(const string * const ani, const int length)
{

	for (int j = 0; j < length; ++j)
		cout << (j % 10 ? ' ' : '\n') << ani[j];

	cout << endl;
}

void quickSort(string a[], int first, int last)
{

	int currentLocation;

	if (first >= last)
		return;
	quickSort(a, first, currentLocation - 1);
	quickSort(a, currentLocation + 1, last);
}

int partition(string b[], int left, int right)
{
	int pos = left;

	while (true)
	{

		while (b[pos] <= b[right] && pos != right)
			right--;

		if (pos == right)
			return pos;

		if (b[pos] > b[right])
		{
			b[pos].swap(b[right]);
			pos = right;
		}

		while (b[left] <= b[pos] && pos != left)
			left++;

		if (pos == left)
			return pos;

		if (b[left] > b[pos])
		{
			b[pos].swap(b[left]);
			pos = left;
		}
	}
}
