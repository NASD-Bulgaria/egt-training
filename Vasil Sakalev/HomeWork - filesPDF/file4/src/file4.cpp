//4. Write a program that reads a text file containing a square matrix of numbers and finds in the
//matrix an area of size 2 x 2 with a maximal sum of its elements. The first line in the input file
//contains the size of matrix N. The next N lines contain N numbers separated by space. The
//output should be a in a separate text file – a single number. Example:
//4
//2 3 3 4
//0 2 3 4 17
//3 7 1 2
//4 3 3 2

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream readMatrix("matrix.txt", ios::in);
	ofstream maxSumOfMatrix("maxSum.txt", ios::out);
	if (!readMatrix) {
		cerr << "The file coud not be opened !!!";
	}
	int size;
	int number;

	while (readMatrix >> number) {
		size = number;
		break;
	}
	int arr[size][size];
	int count = 0;

	for (int i = 0; i < size; i++) {
		while (readMatrix >> number) {
			arr[i][count] = number;
			count++;
		}
		count = 0;
	}

	int maxSum = 0;
	int sum = 0;

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1; j++) {
			sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1];
			if (sum > maxSum) {
				maxSum = sum;
			}
		}
	}
	maxSumOfMatrix << "The maximum sum of 2x2 is : " << maxSum;
	cout << "The maximum sum is: " << maxSum;

	return 0;
}
