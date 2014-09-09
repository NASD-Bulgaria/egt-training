//5. Write a program that extracts from a given file input.txt all words that are
//palindromes, e.g. "ABBA", "lamal", "exe" and stores these words in alphabetical
//order on separate lines in another file – palindromes.txt.

#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

using namespace std;
int main() {

	ifstream readText("text.txt", ios::in);
	ofstream writeText("palindromes.txt" , ios :: out);

	string word;
	string tolowerWord;
	bool check = false;
	while (readText >> word) {
//make word to tolower
		for (unsigned i = 0; i < word.size(); i++) {
			char ch = word.at(i);
			if (isupper(ch)) {
				ch = tolower(ch);
			}
			tolowerWord += ch;
		}

//	clear text from digits
		int position = tolowerWord.find_first_of(".,?!-:();\"", 0);
		while (position != string::npos) {
			tolowerWord.replace(position, 1, "");
			position = tolowerWord.find_first_of(".,?!-:();\"", position);
		}
//check palindrom
		for (unsigned i = 0, j = tolowerWord.size() - 1;
				i < tolowerWord.size() / 2; i++, j--) {

			if (tolowerWord.at(i) == tolowerWord.at(j)) {
				check = true;
			}
		}

		if (check == true) {
			writeText << word << " ";
		}
		tolowerWord = "";
		check = false;
	}

	return 0;
}

