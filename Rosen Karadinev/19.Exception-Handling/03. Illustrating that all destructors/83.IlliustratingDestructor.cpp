#include <iostream>
#include <stdexcept>
#include "TestObject.h"
using namespace std;

int main()
{

	try
	{
		TestObject a(1);
		TestObject b(2);
		TestObject c(3);
		cout << "\n";

		// throw an exception to show that all three Objects created above
		// will have their destructors called before the block expires
		throw runtime_error("This is test exception");
	}
	catch(runtime_error &exception)
	{
		cerr << exception.what() << "\n";
	}
	return 0;
}
