//1. Write a conditional expression that returns either a
//double or an int. Provide an int catch handler and a
//double catch handler. Show that only the double
//catch handler executes, regardless of whether the int
//or the double is returned.

#include <iostream>
using namespace std;

int main()
{
	try
	{
		int a = 0;
		double b = 3.4;
		throw true ? a : b;
	}
	catch (int e)
	{
		cout << "Int throwed!" << endl;
	}
	catch (double e)
	{
		cout << "Double throwed!" << endl;
	}
	return 0;
}
