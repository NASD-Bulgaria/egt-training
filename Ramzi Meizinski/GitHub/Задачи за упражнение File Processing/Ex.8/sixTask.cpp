/*
 * sixTask.cpp
 *
 *  Created on: Aug 29, 2014
 *      Author: Student
 */

#include <iostream>
#include<iomanip>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

int main(){

	ifstream inPutfile ("sixTask.txt", ios::in);
	ofstream outPutfile("sixTaskResult.txt", ios::out);
		if(!inPutfile && !outPutfile)
		{
			cerr << "File could not be opened." << endl;
					exit(1);
		}
		int count = 0;
		string s;

		while (inPutfile >> s)
		{
			count++;
			string result = " ";
			result = result.append(s);
			int position = result.find( " test" );
			int position2 = s.find( "Test" );
			if (position > -1 || position2 > -1)
			{
				outPutfile << "";
			}
			else{
			outPutfile << s << " ";
			}
			if (count % 9 == 0)
			{
				outPutfile << endl;
				count = 0;
			}
		}


	return 0;
}
