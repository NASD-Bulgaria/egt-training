///*
// * liveDemo1.cpp
// *
// *  Created on: Aug 26, 2014
// *      Author: Student
// */
//
//#include <iostream>
//#include <stdexcept>
//using namespace std;
//
//void function3() throw (runtime_error)
//{
//	cout << "In function 3" << endl;
//	throw runtime_error("runtime_error in function3");
//}
//
//void function2() throw (runtime_error)
//		{
//	cout << "function3 is called inside function2" << endl;
//	function3();
//		}
//void function1() throw (runtime_error)
//		{
//	cout << "function2 is called inside function1" << endl;
//	 function2();
//		}
//
//int main()
//{
//
//	try
//	{
//		cout << "function1 is called inside main" << endl;
//     	function1();
//	 }
//	catch (runtime_error &error)
//	{
//		cout << "Exception occurred: " << error.what() << endl;
//		cout << "Exception handled in main" << endl;
//	}
//
//return 0;
//}
