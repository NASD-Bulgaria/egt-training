//Write a program that simulates coin tossing.
//For each toss of the coin, the program should print
//Heads or Tails. Let the program toss the coin 100 times
//and count the number of times each side of the coin appears.
//Print the results. The program should call a separate function
//flip that takes no arguments and returns 0 for tails and 1 for heads.
//[Note: If the program realistically simulates the coin tossing, then each
// side of the coin should appear approximately half the time.]


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int countHead = 0;
int countTails = 0;

void checkCoin(int side)
{
	if(side == 1)
	{
		countHead++;
		cout << "Heads" << endl;
	}
	else
	{
		countTails++;
		cout << "Tails" << endl;
	}
}

int main()
{
	srand(time(0));

	int coin;

	for(int i = 1; i <= 100; i++)
	{
		coin = 1 + rand() % 2;
		cout << "Toss" << i << ": ";
		checkCoin(coin);

	}

	cout << endl;
	cout << "Heads: " << countHead << endl;
	cout << "Tails: " << countTails << endl;

	return 0;
}
