//6. Върху квадратна дъска с размер 6 на 6 клетки са написани последователно
//числата от 1 до 36 (вж. картинката). Редовете и колоните на дъската са
//номерирани с числата от 0 до 5. Върху дъската може многократно да се
//прилага операцията „завъртане на 4 съседни клетки”, която означаваме с
//„Rotate(row,col)”. При завъртането с начална позиция (row, col)
//квадратчетата с координати (row, col), (row, col+1), (row+1, col) и (row+1, col+1)
//се завъртат по часовниковата стрелка (както е показано на фигурата по-долу).
//Даден е текстов файл, който съдържа последователност от команди за
//завъртане. Да се напише програма, която започвайки от началното състояние
//на дъската изпълнява последователно всички команди от входния файл и
//отпечатва състоянието на дъската, което се получава в резултат.
//Входният файл game36.txt съдържа на първия си ред броя команди N (0 < N
//< 1000), които трябва да бъдат изпълнени. На всеки от следващите N реда стои
//по една команда Rotate(row,col), където row и col (числа в интервала [0;
//4]) са съответно редът и колоната, от където започва завъртането. Командите
//са коректно зададени (не излизат извън дъската) и не съдържат в себе си
//интервали или други разделители.
//Изходът съдържа дъската и трябва да се отпечата на конзолата ред по ред.
//Примерен входен файл game36.txt:
//2
//Rotate(2,4)
//Rotate(1,3)

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void Rotate(int arr[][6], int, int);

int main() {

	ifstream readComand("game36.txt", ios::in);

	int arr[6][6];
	int count = 1;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			arr[i][j] = count;
			count++;
		}
	}

	string word;
	readComand.seekg(2);

	while (readComand >> word) {
		for (unsigned i = 0; i < word.size(); i++) {
			if (isdigit(word.at(i))) {
				char r = word.at(i);
				char c = word.at(i+ 2);
				int row = r - '0';
				int col = c - '0';

				Rotate(arr, row, col);
				break;

			}
		}
	}

	readComand.clear();
	readComand.seekg(0);

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

void Rotate(int arr[][6], int row, int col) {
	int temp[2][2];
	temp[0][0] = arr[row][col];
	temp[0][1] = arr[row][col + 1];
	temp[1][0] = arr[row + 1][col];
	temp[1][1] = arr[row + 1][col + 1];

	arr[row][col] = temp[1][0];
	arr[row][col + 1] = temp[0][0];
	arr[row + 1][col] = temp[1][1];
	arr[row + 1][col + 1] = temp[0][1];

}

