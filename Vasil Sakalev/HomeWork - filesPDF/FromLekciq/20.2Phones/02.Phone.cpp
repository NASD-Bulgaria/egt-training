#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <algorithm>

using namespace std;

void words(const int * const);

int main() {
	int number[7] = { 0 };

	cout << "Enter a phone number (keys 2 - 9) like this \"xxx-xxxx\"\n";

	for (int k = 0; k < 7;) {
		int i = cin.get();

		if (i >= '2' && i <= '9')
			number[k++] = i - '0';
	}

	words(number);
}

void words(const int * const num) {
	ofstream wordsFile("phoneNumbers.dat");

	const string phoneLetters[10] = { "", "", "ABC", "DEF", "GHI", "JKL", "MNO",
			"PRS", "TUV", "WXY" };

	if (!wordsFile) {
		cerr << "\"phone.dat\" could not be opened.\n";
		exit(1);
	}

	int count = 0;

	for (int i1 = 0; i1 <= 2; i1++) {
		for (int i2 = 0; i2 <= 2; i2++) {
			for (int i3 = 0; i3 <= 2; i3++) {
				for (int i4 = 0; i4 <= 2; i4++) {
					for (int i5 = 0; i5 <= 2; i5++) {
						for (int i6 = 0; i6 <= 2; i6++) {
							for (int i7 = 0; i7 <= 2; i7++) {
								wordsFile << phoneLetters[num[0]][i1]
										<< phoneLetters[num[1]][i2]
										<< phoneLetters[num[2]][i3]
										<< phoneLetters[num[3]][i4]
										<< phoneLetters[num[4]][i5]
										<< phoneLetters[num[5]][i6]
										<< phoneLetters[num[6]][i7] << ' ';

								if (++count % 9 == 0)
									wordsFile << '\n';
							}
						}
					}
				}
			}
		}
	}

	wordsFile << "\nNumber was ";

	for (int i = 0; i < 7; i++) {
		if (i == 3)
			wordsFile << '-';

		wordsFile << num[i];
	}
}
