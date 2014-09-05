//7. Write a program that generates the following from
//the string "abcdefghijklmnopqrstuvwxyz{":
//             a
//            bcb
//           cdedc
//          defgfed
//         efghihgfe
//        fghijkjihgf
//       ghijklmlkjihg
//      hijklmnonmlkjih
//     ijklmnopqponmlkji
//    jklmnopqrsrqponmlkj
//   klmnopqrstutsrqponmlk
//  lmnopqrstuvwvutsrqponml
// mnopqrstuvwxyxwvutsrqponm
//nopqrstuvwxyz{zyxwvutsrqpon

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	string word = "abcdefghijklmnopqrstuvwxyz{";
	int count = 0;
	string str;
	string str2;
	for (int i = 0; i <= count; i++) {

		for (int j = count; j < i + count + 1; j++) {
			str += word[j];
		}
		for (int k = count-1; k>=0 ; k--) {
			str2 += str[k];
		}
		cout << right << setw(17) << str;
		cout << left << setw(18) << str2 << endl;
		count++;
		if (count > 13) {
			break;
		}

		str2 = "";
		str = "";
	}
	return 0;
}
