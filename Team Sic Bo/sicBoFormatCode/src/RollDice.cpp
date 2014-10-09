
#include "RollDice.h"

RollDice::RollDice()
{
	srand(time(NULL));
}
RollDice::~RollDice() {}

void RollDice::rollAllDices()
{
	setFirstDice();
	setSecondDice();
	setThirdDice();
	sortDices();
}
void RollDice::setFirstDice()
{
	int random = rand() % 6 + 1;
	diceNumbers[0] = random;
}

void RollDice::setSecondDice()
{
	int random = rand() % 6 + 1;
	diceNumbers[1] = random;
}

void RollDice::setThirdDice()
{
	int random = rand() % 6 + 1;
	diceNumbers[2] = random;
}

void RollDice::sortDices()
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<=i; j++)
		{
			if(diceNumbers[i]<diceNumbers[j])
			{
				int temp=diceNumbers[i];
				diceNumbers[i]=diceNumbers[j];
				diceNumbers[j]=temp;
			}
		}
	}

}

void RollDice::nullAllDices()
{
	diceNumbers[0] = 1;
	diceNumbers[1] = 2;
	diceNumbers[2] = 1;
}
int RollDice::getFirstDice()
{
	return diceNumbers[0];
}
int RollDice::getSecondDice()
{
	return diceNumbers[1];
}
int RollDice::getThirdDice()
{
	return diceNumbers[2];
}
