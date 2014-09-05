#include <iostream>
#include <string>
using namespace std;

int main()
{
	string alpha = "abcdefghijklmnopqrstuvwxyz{";
	string::const_iterator x = alpha.begin();
	string::const_iterator x2;

	for (int p = 1; p <= 14; p++)
	{
		int w;
		int count = 0;

		for (int k = 13; k >= p; k--)
			cout << ' ';

		x2 = x;

		for (int c = 1; c <= p; ++c)
		{
			cout << *x2;
			++x2;
			++count;
		}

		for (w = 1, x2 -= 2; w < count; w++)
		{
			cout << *x2;
			--x2;
		}

		++x;
		cout << '\n';
	}

}
