/*6. Write a program that counts the total number of vowels
 in a sentence. Output the frequency of each vowel.
 */
#include <iostream>
#include <string.h>
using namespace std;

void countVowels(string s)
{
		 char charVow;

		 char vowel[] =     {'a', 'e', 'i', 'o', 'u', 'y' };
		 int countVowel[] = { 0,   0,   0,   0,   0,   0 };
		 int len = s.length();


		 for (int i = 0; i < len; i++) {

			 charVow = s[i];
			 switch (tolower(charVow))
			  {
				   case 'a': countVowel[0]++;break;
				   case 'e': countVowel[1]++;break;
				   case 'i': countVowel[2]++;break;
				   case 'o': countVowel[3]++;break;
				   case 'u': countVowel[4]++;break;
				   case 'y': countVowel[5]++;break;
			  }
		 }

			 for (int i = 0; i < 6 ; i++)
			 {
				  if(countVowel[i]!=0)
				  {
					  cout << vowel[i] << " -" << countVowel[i]<<" times"<<endl;
				  }
			 }

}

int main()
{
	string str;

	cout<<"Enter a string: ";
	getline(cin,str);

	countVowels(str);

 return 0;
}
