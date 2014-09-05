//============================================================================
// Name        : HomeWork11-VectorsAndArrays.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

bool checkValidChoice(int);
static const int size = 4;
void MooveKnight(int x, int y, int[][size]);
int main() {
	int chess[size][size] = { 0 };
	int x = 1;
	int y = 0;
	MooveKnight(x, y, chess);
	return 0;
}

void MooveKnight(int x, int y, int chess[][size]) {
	bool allOnes = true;
	if (x < size && x >= 0 && y < size && y >= 0 && chess[x][y] == 0) {
		chess[x][y] = 1;
		cout<<endl;
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				cout<<chess[i][j]<<" ";
			}
			cout<<endl;
		}
		MooveKnight(x - 2, y - 1, chess);
		MooveKnight(x - 2, y + 1, chess);
		MooveKnight(x - 1, y - 2, chess);
		MooveKnight(x - 1, y + 2, chess);
		MooveKnight(x + 2, y - 1, chess);
		MooveKnight(x + 2, y + 1, chess);
		MooveKnight(x + 1, y - 2, chess);
		MooveKnight(x + 1, y + 2, chess);
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (chess[i][j] != 1) {
					allOnes = false;
					break;
				}
			}
			if (!allOnes) {
				break;
			}
		}
		if (allOnes) {
			return;
		}
		chess[x][y] = 0;
	} else {
		return;
	}
}
bool checkValidChoice(int choice) {
	if (choice > 0 && choice <= 10) {
		return true;
	}
	return false;
}
