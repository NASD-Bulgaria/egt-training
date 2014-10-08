#ifndef STATISTICS_H_
#define STATISTICS_H_

using namespace std;

class Statistics
{
public:
	Statistics(int=0, int=0,int=0,int=0);
	virtual ~Statistics();

	int getMaxPayout();
	void setMaxPayout(int);

	void setWinningGames(int);
	int getWinningGames();

	void setLostGames(int);
	int getLostGames();

	void setNumberOfGames(int);
	int getNumberOfGames();

private:
	int numberOfGames;
	int winningGames;
	int lostGames;
	int maxPayout;

};

#endif
