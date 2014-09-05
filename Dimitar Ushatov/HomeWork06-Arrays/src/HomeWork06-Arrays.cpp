//============================================================================
// Name        : HomeWork06-Arrays.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cfloat>
#include <ctime>
#include <climits>
using namespace std;

void DisplaySixtElement() {
	int array[] = { 1, 2, 3, 4, 5, 6 };

	cout << array[5] << endl;
}

void InitialiseArray() {
	int array[5];

	for (int i = 0; i < 5; ++i) {
		array[i] = 8;
		cout << array[i] << (i != 4 ? " " : "\n");
	}
}

void SumFloatArray() {
	float array[100];
	float sum = 0;
	for (int i = 0; i < 100; ++i) {
		array[i] = (rand() % 200) * 0.1f;
		sum += array[i];
	}

	cout << sum << endl;
}

void CopyArray() {
	int firstArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	int secondArray[34] = { 0 };

	for (int i = 0; i < 11; ++i) {
		secondArray[i] = firstArray[i];
	}

	for (int i = 0; i < 34; ++i) {
		cout << secondArray[i] << (i != 33 ? " " : "\n");
	}
}

void FindMinAndMax() {
	float array[99];
	float max = FLT_MIN;
	float min = FLT_MAX;
	srand(time(NULL));
	for (int i = 0; i < 99; ++i) {
		array[i] = (rand() % 500) * 0.1f;
		if (array[i] > max) {
			max = array[i];
		}
		if (array[i] < min) {
			min = array[i];
		}
	}

	cout << "Min element is " << min << endl;
	cout << "Max element is " << max << endl;
}

void DeclareMatrix() {
	const int rows = 2;
	const int cols = 3;

	int array[rows][cols] = { { 1, 2, 3 }, { 4, 5, 6 } };

	for (int col = 0; col < cols; ++col) {
		cout << array[0][col] << ((col != cols - 1) ? " " : "\n");
	}
}

void SolveDice() {
	int trowedCombinations[11] = { 0 };
	int firstDice, secondDice;

	srand(time(NULL));

	for (int round = 0; round < 36000000; ++round) {
		firstDice = 1 + rand() % 6;
		secondDice = 1 + rand() % 6;
		trowedCombinations[firstDice + secondDice - 2]++;
	}

	for (int combination = 0; combination < 11; ++combination) {
		cout << "The combination " << combination + 2 << " is trowed "
				<< trowedCombinations[combination] << " times!" << endl;
	}
}

void IndexesTimes5() {
	int array[20];
	for (int index = 0; index < 20; ++index) {
		array[index] = index * 5;
	}
}

void CompareArrays() {
	cout << "Enter the size of the first array" << endl;
	int n;
	cin >> n;
	cout << "Enter the size of the second array" << endl;
	int m;
	cin >> m;

	int firstArray[n];
	int secondArray[m];
	bool equal = true;
	if (n == m) {
		for (int index = 0; index < n; ++index) {
			if (firstArray[index] != secondArray[index]) {
				equal = false;
				break;
			}
		}

		if (equal) {
			cout << "The arrays are equal" << endl;
		} else {
			cout << "The arrays are not equal" << endl;
		}
	} else {
		cout << "The arrays are not equal" << endl;
	}
}

void FindMaxSeq() {
	cout << "Enter the size of the array" << endl;
	int n;
	cin >> n;
	int array[n];
	for (int index = 0; index < n; ++index) {
		cout << "Enter element " << index << endl;
		cin >> array[index];
	}

	int maxCount = 0;
	int currentCount = 0;
	int bestElementIndex = 0;
	int cuurentElementIndex;

	for (int index = 0; index < n;) {
		cuurentElementIndex = index;
		currentCount = 0;
		while (index < n && array[cuurentElementIndex] == array[index]) {
			currentCount++;
			index++;
		}

		if (currentCount > maxCount) {
			maxCount = currentCount;
			bestElementIndex = cuurentElementIndex;
		} else if (currentCount == maxCount) {
			if (array[cuurentElementIndex] > array[bestElementIndex]) {
				bestElementIndex = cuurentElementIndex;
			}
		}
	}

	for (int index = bestElementIndex; index < bestElementIndex + maxCount;
			++index) {
		cout << array[index] << " ";
	}
	cout << endl;
}

void FindMaxSumOf3x3() {
	cout << "Enter the count of the rows in array" << endl;
	int n;
	cin >> n;
	cout << "Enter the count of the cols in array" << endl;
	int m;
	cin >> m;

	int matrix[n][m];

	int currentSum, bestRow, bestCol;
	int maxSum = INT_MIN;

	for (int row = 0; row <= n - 3; ++row) {
		for (int col = 0; col <= m - 3; ++col) {
			currentSum = 0;
			for (int insRow = row; insRow < row + 3; ++insRow) {
				for (int insCol = col; insCol < col + 3; ++insCol) {
					currentSum += matrix[insRow][insCol];
				}
			}

			if (currentSum > maxSum) {
				maxSum = currentSum;
				bestRow = row;
				bestCol = col;
			}
		}
	}

	for (int row = bestRow; row < bestRow + 3; ++row) {
		for (int col = bestCol; col < bestCol + 3; ++col) {
			cout << matrix[row][col] << " ";
		}
		cout << endl;
	}
}

void Task31() {
	srand(time(NULL));
	int n = 1 + rand() % 100;
	int arrayA[n];
	int arrayB[n];
	int sum = 0;
	for (int index = 0; index < n; ++index) {
		arrayA[index] = rand() % 200;
	}

	for (int index = 0; index < n; ++index) {
		sum = 0;
		for (int indexSum = index; indexSum < n; ++indexSum) {
			sum += arrayA[indexSum];
		}
		arrayB[index] = sum;
	}
	cout << "First array:" << endl;
	for (int index = 0; index < n; ++index) {
		cout << arrayA[index] << " ";
	}
	cout << endl;
	cout << "Second array:" << endl;
	for (int index = 0; index < n; ++index) {
		cout << arrayB[index] << " ";
	}
	cout << endl;
}

void Task32() {
	int n = 5;
	int arrayA[n];
	int arrayB[n];
	int arrayC[2 * n];
	srand(time(NULL));
	int startA = 1;
	int startB = 1;
	for (int index = 0; index < n; ++index) {
		arrayA[index] = startA + rand() % 100;
		arrayB[index] = startB + rand() % 100;
		startA = arrayA[index];
		startB = arrayB[index];
	}

	for (int indexA = 0, indexB = 0; indexA < n || indexB < n;) {
		if (arrayA[indexA] > arrayB[indexB]) {
			arrayC[indexA + indexB] = arrayB[indexB];
			indexB++;
		} else {
			arrayC[indexA + indexB] = arrayA[indexA];
			indexA++;
		}
	}

	for (int index = 0; index < n; ++index) {
		cout << arrayA[index] << " ";
	}
	cout << endl;
	for (int index = 0; index < n; ++index) {
		cout << arrayB[index] << " ";
	}
	cout << endl;
	for (int index = 0; index < 2 * n; ++index) {
		cout << arrayC[index] << " ";
	}
	cout << endl;
}

void Task33() {
	int nA = 5;
	int nB = 10;
	int nC = 15;
	int arrayA[nA];
	int arrayB[nB];
	int arrayC[nC];
	int arrayD[nA + nB + nC];
	srand(time(NULL));
	int startA = 1;
	int startB = 1;
	int startC = 1;
	for (int index = nA - 1; index >= 0; --index) {
		arrayA[index] = startA + rand() % 100;
		startA = arrayA[index];
	}
	for (int index = nB - 1; index >= 0; --index) {
		arrayB[index] = startB + rand() % 100;
		startB = arrayB[index];
	}
	for (int index = nC - 1; index >= 0; --index) {
		arrayC[index] = startC + rand() % 100;
		startC = arrayC[index];
	}
	int indexD = nA + nB + nC - 1;
	for (int indexA = nA - 1, indexB = nB - 1, indexC =  nC - 1;
			indexD >= 0;) {
		if (arrayA[indexA] >= arrayB[indexB]
				&& arrayB[indexB] <= arrayC[indexC]) {
			arrayD[indexD] = arrayB[indexB];
			indexB--;
		} else if (arrayB[indexB] >= arrayA[indexA]
				&& arrayA[indexA] <= arrayC[indexC]) {
			arrayD[indexD] = arrayA[indexA];
			indexA--;
		} else if (arrayB[indexB] >= arrayC[indexC]
				&& arrayC[indexC] <= arrayA[indexA]) {
			arrayD[indexD] = arrayC[indexC];
			indexC--;
		}
		indexD--;
	}

	for (int index = 0; index < nA; ++index) {
		cout << arrayA[index] << " ";
	}
	cout << endl;
	for (int index = 0; index < nB; ++index) {
		cout << arrayB[index] << " ";
	}
	cout << endl;
	for (int index = 0; index < nC; ++index) {
		cout << arrayC[index] << " ";
	}
	cout << endl;
	for (int index = 0; index < (nC + nB + nA); ++index) {
		cout << arrayD[index] << " ";
	}
	cout << endl;

}

int main() {
//	DisplaySixtElement();
//	InitialiseArray();
//	SumFloatArray();
//	CopyArray();
//	FindMinAndMax();
//	DeclareMatrix();
//	SolveDice();
//	FindMaxSeq();
//	Task31();
//	Task32();
	Task33();
	return 0;
}
