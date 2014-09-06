//============================================================================
// Name        : Strings.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include <iostream>

using namespace std;

int main() {


	ifstream inf("Sample.dat");
	ofstream onf("Sorted.dat");


	if (!inf) {

		cerr << "Sample.dat could not be opened for reading!" << endl;

	}
	int size;
inf >> size;

int arr[size][size];



	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			inf >> arr[i][j];

		}
	}
	int sum = 0;
	int check = 0;
	for(int i = 0; i < size - 1; i++){
			for(int j = 0; j < size - 1; j++){
				check = arr[i][j] + arr[i][j + 1] +
						arr[i+1][j] + arr[i+1][j+1];
				if(check > sum){
					sum = check;
				}
			}

		}
	onf << sum;
	onf.close();

	return 0;

}
