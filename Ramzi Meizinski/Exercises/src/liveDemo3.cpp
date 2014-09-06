///*
// * liveDemo3.cpp
// *
// *  Created on: Aug 27, 2014
// *      Author: Student
// */
//
//#include <iostream>
//#include <fstream>
//#include <cstdlib>
//using namespace std;
//
//#include "ClientData.h"
//
//int main(){
//
//	ofstream outCredit ("credit.dat", ios::binary);
//
//	if ( !outCredit )
//	{
//	cerr << "File could not be opened." << endl;
//	exit( 1 );
//	}
//
//	ClientData blankClient;
//	for ( int i = 0; i < 100; i++ ){
//		outCredit.write( reinterpret_cast< const char * >( &blankClient ),
//		sizeof( ClientData ) );
//
//	}
//
//
//
//	return 0;
//}
