#ifndef BUTTON_H_
#define BUTTON_H_
#include <SDL2/SDL.h>
#include "RollDice.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//#include <SDL2/SDL_image.h>

struct buttonTypes
{
	int buttonType;
	int bet;
	int win;
};

class Button : public RollDice
{
private:
	SDL_Surface *localScreen;
	SDL_Surface *buttonImage;
	SDL_Rect buttonRect;
	SDL_Event event;
	int mouseX,mouseY;
	buttonTypes sTypes;

public:

	Button(int x, int y, int h, int w, SDL_Surface *image, SDL_Surface *screen);
	virtual ~Button();

	void drawToScreen(int);
	bool checkEvents(SDL_Event *);
	SDL_Surface* getImage();

	//Set/get button type, button bet, and button payout
//	void setTypes(int);

	void setBet(int);
	void setWin(int);
	int getBet();
	int getWin();
	void nullBetAndWin();
	void clearButtons();

	void check1000(int);
	void check200(int);
	void check175(int);
	void check125(int);
	void check100(int);
	void check60(int);
	void check50(int);
	void check25(int);
	void check10(int);

	void checkAllButton(int,int,int);
	void checkSmall(int,int,int);
	void specificDouble1(int,int,int);
	void specificDouble2(int,int,int);
	void specificDouble3(int,int,int);
	void specificDouble4(int,int,int);
	void specificDouble5(int,int,int);
	void specificDouble6(int,int,int);
	void specificTriple1(int,int,int);
	void specificTriple2(int,int,int);
	void specificTriple3(int,int,int);
	void specificTriple4(int,int,int);
	void specificTriple5(int,int,int);
	void specificTriple6(int,int,int);
	void anyTriple(int,int,int);
	void checkBig(int,int,int);
	void checkTotal_4(int,int,int);
	void checkTotal_5(int,int,int);
	void checkTotal_6(int,int,int);
	void checkTotal_7(int,int,int);
	void checkTotal_8(int,int,int);
	void checkTotal_9(int,int,int);
	void checkTotal_10(int,int,int);
	void checkTotal_11(int,int,int);
	void checkTotal_12(int,int,int);
	void checkTotal_13(int,int,int);
	void checkTotal_14(int,int,int);
	void checkTotal_15(int,int,int);
	void checkTotal_16(int,int,int);
	void checkTotal_17(int,int,int);
	void pairMatch_1_2(int,int,int);
	void pairMatch_1_3(int,int,int);
	void pairMatch_1_4(int,int,int);
	void pairMatch_1_5(int,int,int);
	void pairMatch_1_6(int,int,int);
	void pairMatch_2_3(int,int,int);
	void pairMatch_2_4(int,int,int);
	void pairMatch_2_5(int,int,int);
	void pairMatch_2_6(int,int,int);
	void pairMatch_3_4(int,int,int);
	void pairMatch_3_5(int,int,int);
	void pairMatch_3_6(int,int,int);
	void pairMatch_4_5(int,int,int);
	void pairMatch_4_6(int,int,int);
	void pairMatch_5_6(int,int,int);
	void singleDice_1(int,int,int);
	void singleDice_2(int,int,int);
	void singleDice_3(int,int,int);
	void singleDice_4(int,int,int);
	void singleDice_5(int,int,int);
	void singleDice_6(int,int,int);
	void specStraight_1_2_3(int,int,int);
	void specStraight_2_3_4(int,int,int);
	void specStraight_3_4_5(int,int,int);
	void specStraight_4_5_6(int,int,int);
	void anyStraight(int,int,int);

};

#endif /* BUTTON_H_ */
