//Write a recursive function gcd that returns the greatest common divisor of x and y.
//[Note: For this algorithm, x must be larger than y.]

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if(b == 0)
	{
	        return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}

int main()
{
	int a, b;
	cout << "a= ";
	cin >> a;

	cout << "b= ";
	cin >> b;


	cout << gcd(a,b);

	return 0;
}
