#ifndef ROLLDICE_H_
#define ROLLDICE_H_
#include <cstdlib>
#include <ctime>

using namespace std;
class RollDice
{
private:
	int diceNumbers[3];
public:
	RollDice();
	virtual ~RollDice();

	void rollAllDices();
	void setFirstDice();
	void setSecondDice();
	void setThirdDice();

	int getFirstDice();
	int getSecondDice();
	int getThirdDice();


};

#endif /* ROLLDICE_H_ */
