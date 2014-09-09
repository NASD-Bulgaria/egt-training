//4. Напишете програма, която кодира дадено съобщение по следния начин:
//символите от съобщението се попълват по колони в квадратна матрица, а
//кодираното съобщение се получава като се прочете матрицата по редове.
//Съобщението се прочита от входен файл message.txt, а кодираното
//съобщение се записва в изходен файл encoded-message.txt. Разкодирате
//кодираното в encoded-message.txt съобщение и принтирайте на конзолата
//резултата – той трябва да съвпада със съобщението, записано в message.txt.
//Размерът на квадратната матрица се определя от дължината на съобщението
//(т.е. най-малкото цяло число n, такова че n*n >= дължината на текста).

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
	ifstream readText("message.txt", ios::in);
	ofstream writeText("encoded-message.txt", ios::out);

	if (!readText) {
		cerr << "The file coud not be opened !!! ";
	}
//Read and code message from file to file
	string word;
	string message;
	while (readText >> word) {
		message.append(word + " ");
	}
	int size = sqrt(message.size()) + 1;

	char arr[size][size];
	unsigned count = 0;
	for (int j = 0; j < size; j++) {
		for (int i = 0; i < size; i++) {
			if (count != message.size()) {
				arr[i][j] = message.at(count);
				count++;
			} else {
				arr[i][j] = ' ';
			}

		}
	}

	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size; j++) {
			writeText << arr[i][j];
		}
	}

	writeText.clear();
	writeText.seekp(0);

//decript message from file
	ifstream readCod("encoded-message.txt", ios::in);
	if (!readCod) {
		cerr << "The file coud not be opened !!!";
	}

	string line;
	while (!readCod.eof()) {
		getline(readCod, line);
	}

	size = sqrt(line.size()) ;
	count = 0;
	char arr2[size][size];
	count = 0;

	for (int i = 0; i < size ; i++) {
		for (int j = 0; j < size ; j++) {

			if (count != line.size()) {
				arr2[i][j] = line.at(count);
				count++;

			} else {
				arr2[i][j] = ' ';
				count++;
			}
		}
	}
	for (int j = 0; j < size; j++) {

		for (int i = 0; i < size; i++) {
			cout << arr2[i][j];
		}
	}
	return 0;
}
