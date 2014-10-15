#ifndef ROLLDICE_H_
#define ROLLDICE_H_
#include <cstdlib>
#include <ctime>

using namespace std;
class RollDice
{
protected:
	int diceNumbers[3];
public:
	RollDice();
	virtual ~RollDice();

	void rollAllDices();
	void setFirstDice();
	void setSecondDice();
	void setThirdDice();

	void sortDices();

	int getFirstDice();
	int getSecondDice();
	int getThirdDice();

	void nullAllDices();
};

#endif /* ROLLDICE_H_ */
