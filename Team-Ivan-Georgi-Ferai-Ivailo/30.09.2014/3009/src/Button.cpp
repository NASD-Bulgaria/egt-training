#include "Button.h"
//Constructor


Button::Button(int x,int y,int w,int h,SDL_Surface * image,SDL_Surface * screen):
localScreen(screen), mouseX(0), mouseY(0)
{
	buttonImage = image;
	buttonRect.x = x;
	buttonRect.y = y;
	buttonRect.h = h;
	buttonRect.w = w;
}

//Destructor
Button::~Button() {}
//Draw the button/image on the backGround
void Button::drawToScreen(int type)
{
	SDL_BlitSurface(buttonImage,NULL,localScreen,&buttonRect);
	sTypes.buttonType = type;
	sTypes.bet = 0;
	sTypes.win = 0;
}
//Find which button is clicled by mouse
bool Button::checkEvents(SDL_Event *e)
{
	bool result = false;
	if( e->type == SDL_MOUSEBUTTONDOWN)
	{
		int xCord, yCord;
		SDL_GetMouseState( &xCord, &yCord );
		bool inside = true;

		//Mouse is left of the button
		if( xCord < buttonRect.x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( xCord > buttonRect.x + buttonRect.w )
		{
			inside = false;
		}
		//Mouse above the button
		else if( yCord < buttonRect.y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( yCord > buttonRect.y + buttonRect.h )
		{
			inside = false;
		}
		if(inside == true)
		{
			result = true;
		}
	}
	return result;
}
SDL_Surface* Button::getImage()
{
	return buttonImage;
}
//
//void Button::setTypes(int type)
//{
//	sTypes.buttonType = type;
//	sTypes.bet = 0;
//	sTypes.win = 0;
//}
void Button::nullBetAndWin()
{
	sTypes.bet = 0;
	sTypes.win = 0;
}

void Button::check1000(int bet)
{
	//check if max bet is over 1000
	if((sTypes.buttonType == 1 || sTypes.buttonType == 15) ||
			(sTypes.buttonType >= 45 && sTypes.buttonType <= 50))
	{
		if(sTypes.bet >= 1000)
		{
			sTypes.bet = 1000;
		}
	}
}
void Button::check200(int bet)
{
	//check if max bet is over 200
	if((sTypes.buttonType == 22 || sTypes.buttonType == 23) ||
	   (sTypes.buttonType <= 44 && sTypes.buttonType >= 30))
	{
		if(sTypes.bet >= 200)
		{
			sTypes.bet = 200;
		}
	}
}
void Button::check175(int bet)
{
	//check if max bet is over 175
	if(sTypes.buttonType == 21 || sTypes.buttonType == 24)
	{
		if(sTypes.bet >= 175)
		{
			sTypes.bet = 175;
		}
	}
}
void Button::check125(int bet)
{
	//check if max bet is over 125
	if((sTypes.buttonType == 20 || sTypes.buttonType == 25) ||
	   (sTypes.buttonType == 51))
	{
		if(sTypes.bet >= 125)
		{
			sTypes.bet = 125;
		}
	}
}
void Button::check100(int bet)
{
	//check if max bet is over 100
	if((sTypes.buttonType == 19 || sTypes.buttonType == 26) ||
	  (sTypes.buttonType >= 2 && sTypes.buttonType <= 7))
	{
		if(sTypes.bet >= 100)
		{
			sTypes.bet = 100;
		}
	}
}
void Button::check60(int bet)
{
	//check if max bet is over 60
	if(sTypes.buttonType == 18 || sTypes.buttonType == 27)
	{
		if(sTypes.bet >= 60)
		{
			sTypes.bet = 60;
		}
	}
}
void Button::check50(int bet)
{
	//check if max bet is over 50
	if(((sTypes.buttonType == 17 || sTypes.buttonType == 28) ||
		(sTypes.buttonType <= 55 && sTypes.buttonType >= 52)) ||
			(sTypes.buttonType == 14))
	{
		if(sTypes.bet >= 50)
		{
			sTypes.bet = 50;
		}
	}
}
void Button::check25(int bet)
{
	//check if max bet is over 25
	if(sTypes.buttonType == 16 || sTypes.buttonType == 29)
	{
		if(sTypes.bet >= 25)
		{
			sTypes.bet = 25;
		}
	}
}
void Button::check10(int bet)
{
	//check if max bet is over 10
	if(sTypes.buttonType >= 8 && sTypes.buttonType <= 13)
	{
		if(sTypes.bet >= 10)
		{
			sTypes.bet = 10;
		}
	}
}

void Button::setBet(int bet)
{
	sTypes.bet += bet;
	check1000(sTypes.bet);
	check200(sTypes.bet);
	check175(sTypes.bet);
	check125(sTypes.bet);
	check100(sTypes.bet);
	check60(sTypes.bet);
	check50(sTypes.bet);
	check25(sTypes.bet);
	check10(sTypes.bet);
}
void Button::setWin(int win)
{
	sTypes.win = win;
}
int Button::getBet()
{
	return sTypes.bet;
}
int Button::getWin()
{
	return sTypes.win;
}

void Button::checkAllButton(int a,int b,int c)
{
	checkSmall(a,b,c);

	specificDouble1(a,b,c);
	specificDouble2(a,b,c);
	specificDouble3(a,b,c);
	specificDouble4(a,b,c);
	specificDouble5(a,b,c);
	specificDouble6(a,b,c);

	specificTriple1(a,b,c);
	specificTriple2(a,b,c);
	specificTriple3(a,b,c);
	specificTriple4(a,b,c);
	specificTriple5(a,b,c);
	specificTriple6(a,b,c);
	anyTriple(a,b,c);

	checkBig(a,b,c);

	checkTotal_4(a,b,c);
	checkTotal_5(a,b,c);
	checkTotal_6(a,b,c);
	checkTotal_7(a,b,c);
	checkTotal_8(a,b,c);
	checkTotal_9(a,b,c);
	checkTotal_10(a,b,c);
	checkTotal_11(a,b,c);
	checkTotal_12(a,b,c);
	checkTotal_13(a,b,c);
	checkTotal_14(a,b,c);
	checkTotal_15(a,b,c);
	checkTotal_16(a,b,c);
	checkTotal_17(a,b,c);

	pairMatch_1_2(a,b,c);
	pairMatch_1_3(a,b,c);
	pairMatch_1_4(a,b,c);
	pairMatch_1_5(a,b,c);
	pairMatch_1_6(a,b,c);
	pairMatch_2_3(a,b,c);
	pairMatch_2_4(a,b,c);
	pairMatch_2_5(a,b,c);
	pairMatch_2_6(a,b,c);
	pairMatch_3_4(a,b,c);
	pairMatch_3_5(a,b,c);
	pairMatch_3_6(a,b,c);
	pairMatch_4_5(a,b,c);
    pairMatch_4_6(a,b,c);
	pairMatch_5_6(a,b,c);

	singleDice_1(a,b,c);
	singleDice_2(a,b,c);
	singleDice_3(a,b,c);
	singleDice_4(a,b,c);
	singleDice_5(a,b,c);
	singleDice_6(a,b,c);

	specStraight_1_2_3(a,b,c);
	specStraight_2_3_4(a,b,c);
	specStraight_3_4_5(a,b,c);
	specStraight_4_5_6(a,b,c);
	anyStraight(a,b,c);
}

void Button::checkSmall(int a ,int b,int c)
{
	//Button Type = 1
	int sum = a + b + c;
	if(sTypes.buttonType == 1)
	{
		if((sum <=10 && sum >= 4)&&(a!=b||a!=c))
		{

			sTypes.win += sTypes.bet + sTypes.bet;
			SDL_SetSurfaceBlendMode(getImage(),SDL_BLENDMODE_ADD);
		}
	}
}

void Button::specificDouble1(int a,int b,int c)
{
	//Button type = 2
	if(sTypes.buttonType == 2)
	{
		if((a == 1 && b == 1) || ((a == 1 && c == 1 ) || (b == 1 && c == 1)))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*11));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::specificDouble2(int a,int b,int c)
{
	//Button type = 3
	if(sTypes.buttonType == 3)
	{
		if((a == 2 && b == 2) || ((a == 2 && c == 2 ) || (b == 2 && c == 2)))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*11));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::specificDouble3(int a,int b,int c)
{
	//Button type = 4
	if(sTypes.buttonType == 4)
	{
		if((a == 3 && b == 3) || ((a == 3 && c == 3 ) || (b == 3 && c == 3)))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*11));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::specificDouble4(int a,int b,int c)
{
	//Button type = 5
	if(sTypes.buttonType == 5)
	{
		if((a == 4 && b == 4) || ((a == 4 && c == 4 ) || (b == 4 && c == 4)))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*11));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::specificDouble5(int a,int b,int c)
{
	//Button type = 6
	if(sTypes.buttonType == 6)
	{
		if((a == 5 && b == 5) || ((a == 5 && c == 5 ) || (b == 5 && c == 5)))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*11));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::specificDouble6(int a,int b,int c)
{
	//Button type = 7
	if(sTypes.buttonType == 7)
	{
		if((a == 6 && b == 6) || ((a == 6 && c == 6 ) || (b == 6 && c == 6)))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*11));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}

void Button::specificTriple1(int a,int b ,int c)
{
	//Button type = 8
	if(sTypes.buttonType == 8)
	{
		if(a == 1 && (b == 1 && c == 1))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*180));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::specificTriple2(int a,int b ,int c)
{
	//Button type = 9
	if(sTypes.buttonType == 9)
	{
		if(a == 2 && (b == 2 && c == 2))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*180));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::specificTriple3(int a,int b ,int c)
{
	//Button type = 10
	if(sTypes.buttonType == 10)
	{
		if(a == 3 && (b == 3 && c == 3))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*180));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::specificTriple4(int a,int b ,int c)
{
	//Button type = 11
	if(sTypes.buttonType == 11)
	{
		if(a == 4 && (b == 4 && c == 4))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*180));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::specificTriple5(int a,int b ,int c)
{
	//Button type = 12
	if(sTypes.buttonType == 12)
	{
		if(a == 5 && (b == 5 && c == 5))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*180));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::specificTriple6(int a,int b ,int c)
{
	//Button type = 13
	if(sTypes.buttonType == 13)
	{
		if(a == 6 && (b == 6 && c == 6))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*180));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::anyTriple(int a,int b ,int c)
{
	//Button type = 14
	if(sTypes.buttonType == 14)
	{
		if(a == b && a == c)
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*31));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}

void Button::checkBig(int a ,int b,int c)
{
	//button type 15
	int sum = a + b + c;
	if(sTypes.buttonType == 15)
	{
		if((sum <=17 && sum >= 11)&&(a!=b||a!=c))
		{

			sTypes.win += (sTypes.bet + sTypes.bet);
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);

		}
	}
}

void Button::checkTotal_4(int a,int b ,int c)
{
	//button type 16
	int sum = a + b + c;
	if(sTypes.buttonType == 16)
	{
		if(sum == 4)
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*62));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::checkTotal_5(int a,int b ,int c)
{
	//button type 17
	int sum = a + b + c;
	if(sTypes.buttonType == 17)
	{
		if(sum == 5)
		{
			sTypes.win = (sTypes.bet + (sTypes.bet*31));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::checkTotal_6(int a,int b ,int c)
{
	//button type 18
	int sum = a + b + c;
	if(sTypes.buttonType == 18)
	{
		if(sum == 6)
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*18));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::checkTotal_7(int a,int b ,int c)
{
	//button type 19
	int sum = a + b + c;
	if(sTypes.buttonType == 19)
	{
		if(sum == 7)
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*12));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::checkTotal_8(int a,int b ,int c)
{
	//button type 20
	int sum = a + b + c;
	if(sTypes.buttonType == 20)
	{
		if(sum == 8)
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*8));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::checkTotal_9(int a,int b ,int c)
{
	//button type 21
	int sum = a + b + c;
	if(sTypes.buttonType == 21)
	{
		if(sum == 9)
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*7));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::checkTotal_10(int a,int b ,int c)
{
	//button type 22
	int sum = a + b + c;
	if(sTypes.buttonType == 22)
	{
		if(sum == 10)
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*6));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::checkTotal_11(int a,int b ,int c)
{
	//button type 23
	int sum = a + b + c;
	if(sTypes.buttonType == 23)
	{
		if(sum == 11)
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*6));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::checkTotal_12(int a,int b ,int c)
{
	//button type 24
	int sum = a + b + c;
	if(sTypes.buttonType == 24)
	{
		if(sum == 12)
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*7));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::checkTotal_13(int a,int b ,int c)
{
	//button type 25
	int sum = a + b + c;
	if(sTypes.buttonType == 25)
	{
		if(sum == 13)
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*8));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::checkTotal_14(int a,int b ,int c)
{
	//button type 26
	int sum = a + b + c;
	if(sTypes.buttonType == 26)
	{
		if(sum == 14)
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*12));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::checkTotal_15(int a,int b ,int c)
{
	//button type 27
	int sum = a + b + c;
	if(sTypes.buttonType == 27)
	{
		if(sum == 15)
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*18));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::checkTotal_16(int a,int b ,int c)
{
	//button type 28
	int sum = a + b + c;
	if(sTypes.buttonType == 28)
	{
		if(sum == 16)
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*31));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::checkTotal_17(int a,int b ,int c)
{
	//button type 29
	int sum = a + b + c;
	if(sTypes.buttonType == 29)
	{
		if(sum == 17)
		{

			sTypes.win = (sTypes.bet + (sTypes.bet*62));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}

void Button::pairMatch_1_2(int a,int b ,int c)
{
	//Button type 30
	if(sTypes.buttonType == 30)
	{
		if (((a == 1 && (b == 2 || c == 2)) || (b == 1 && (a==2 || c ==2))) || (c == 1 && (a == 2 || b == 2)))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet * 6));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::pairMatch_1_3(int a,int b ,int c)
{
	//Button type 31
	if(sTypes.buttonType == 31)
	{
		if (((a == 1 && (b == 3 || c == 3)) || (b == 1 && (a==3 || c ==3))) || (c == 1 && (a == 3 || b == 3)))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet * 6));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::pairMatch_1_4(int a,int b ,int c)
{
	//Button type 32
	if(sTypes.buttonType == 32)
	{
		if (((a == 1 && (b == 4 || c == 4)) || (b == 1 && (a==4 || c ==4))) || (c == 1 && (a == 4 || b == 4)))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet * 6));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::pairMatch_1_5(int a,int b ,int c)
{
	//Button type 33
	if(sTypes.buttonType == 33)
	{
		if (((a == 1 && (b == 5 || c == 5)) || (b == 1 && (a==5 || c ==5))) || (c == 1 && (a == 5 || b == 5)))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet * 6));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::pairMatch_1_6(int a,int b ,int c)
{
	//Button type 34
	if(sTypes.buttonType == 34)
	{
		if (((a == 1 && (b == 6 || c == 6)) || (b == 1 && (a==6 || c ==6))) || (c == 1 && (a == 6 || b == 6)))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet * 6));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::pairMatch_2_3(int a,int b ,int c)
{
	//Button type 35
	if(sTypes.buttonType == 35)
	{
		if (((a == 2 && (b == 3 || c == 3)) || (b == 2 && (a== 3 || c == 3))) || (c == 2 && (a == 3 || b == 3)))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet * 6));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::pairMatch_2_4(int a,int b ,int c)
{
	//Button type 36
	if(sTypes.buttonType == 36)
	{
		if (((a == 2 && (b == 4 || c == 4)) || (b == 2 && (a== 4 || c == 4))) || (c == 2 && (a == 4 || b == 4)))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet * 6));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::pairMatch_2_5(int a,int b ,int c)
{
	//Button type 37
	if(sTypes.buttonType == 37)
	{
		if (((a == 2 && (b == 5 || c == 5)) || (b == 2 && (a== 5 || c == 5))) || (c == 2 && (a == 5 || b == 5)))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet * 6));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::pairMatch_2_6(int a,int b ,int c)
{
	//Button type 38
	if(sTypes.buttonType == 38)
	{
		if (((a == 2 && (b == 6 || c == 6)) || (b == 2 && (a == 6 || c == 6))) || (c == 2 && (a == 6 || b == 6)))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet * 6));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::pairMatch_3_4(int a,int b ,int c)
{
	//Button type 39
	if(sTypes.buttonType == 39)
	{
		if (((a == 3 && (b == 4 || c == 4)) || (b == 3 && (a == 4 || c == 4))) || (c == 3 && (a == 4 || b == 4)))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet * 6));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::pairMatch_3_5(int a,int b ,int c)
{
	//Button type 40
	if(sTypes.buttonType == 40)
	{
		if (((a == 3 && (b == 5 || c == 5)) || (b == 3 && (a == 5 || c == 5))) || (c == 3 && (a == 5 || b == 5)))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet * 6));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::pairMatch_3_6(int a,int b ,int c)
{
	//Button type 41
	if(sTypes.buttonType == 41)
	{
		if (((a == 3 && (b == 6 || c == 6)) || (b == 3 && (a == 6 || c == 6))) || (c == 3 && (a == 6 || b == 6)))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet * 6));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::pairMatch_4_5(int a,int b ,int c)
{
	//Button type 42
	if(sTypes.buttonType == 42)
	{
		if (((a == 4 && (b == 5 || c == 5)) || (b == 4 && (a == 5 || c == 5))) || (c == 4 && (a == 5 || b == 5)))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet * 6));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::pairMatch_4_6(int a,int b ,int c)
{
	//Button type 43
	if(sTypes.buttonType == 43)
	{
		if (((a == 4 && (b == 6 || c == 6)) || (b == 4 && (a == 6 || c == 6))) || (c == 4 && (a == 6 || b == 6)))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet * 6));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::pairMatch_5_6(int a,int b ,int c)
{
	//Button type 44
	if(sTypes.buttonType == 44)
	{
		if (((a == 5 && (b == 6 || c == 6)) || (b == 5 && (a == 6 || c == 6))) || (c == 5 && (a == 6 || b == 6)))
		{

			sTypes.win = (sTypes.bet + (sTypes.bet * 6));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}

void Button::singleDice_1(int a,int b ,int c)
{
	//Button type 45
	if(sTypes.buttonType == 45)
	{
		if((a == 1 && b != 1 && c != 1) || ((b == 1 && a != 1 && c != 1) || (c == 1 && a != 1 && b != 1)))
		{
			sTypes.win = sTypes.bet + sTypes.bet;
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
		else if((a == 1 && b == 1 && c != 1) || ((a == 1 && c == 1 && b != 1) || (b == 1 && c == 1 && a != 1)))
		{
			sTypes.win = (sTypes.bet + (sTypes.bet*2));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
		else if(a == 1 && b == 1 && c == 1)
		{
			sTypes.win = (sTypes.bet + (sTypes.bet*12));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::singleDice_2(int a,int b ,int c)
{
	//Button type 46
	if(sTypes.buttonType == 46)
	{
		if((a == 2 && b != 2 && c != 2) || ((b == 2 && a != 2 && c != 2) || (c == 2 && a != 2 && b != 2)))
		{
			sTypes.win = sTypes.bet + sTypes.bet;
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
		else if((a == 2 && b == 2 && c != 2) || ((a == 2 && c == 2 && b != 2) || (b == 2 && c == 2 && a != 2)))
		{
			sTypes.win = (sTypes.bet + (sTypes.bet*2));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
		else if(a == 2 && b == 2 && c == 2)
		{
			sTypes.win = (sTypes.bet + (sTypes.bet*12));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::singleDice_3(int a,int b ,int c)
{
	//Button type 47
	if(sTypes.buttonType == 47)
	{
		if((a == 3 && b != 3 && c != 3) || ((b == 3 && a != 3 && c != 3) || (c == 3 && a != 3 && b != 3)))
		{
			sTypes.win = sTypes.bet + sTypes.bet;
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
		else if((a == 3 && b == 3 && c != 3) || ((a == 3 && c == 3 && b != 3) || (b == 3 && c == 3 && a != 3)))
		{
			sTypes.win = (sTypes.bet + (sTypes.bet*2));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
		else if(a == 3 && b == 3 && c == 3)
		{
			sTypes.win = (sTypes.bet + (sTypes.bet*12));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::singleDice_4(int a,int b ,int c)
{
	//Button type 48
	if(sTypes.buttonType == 48)
	{
		if((a == 4 && b != 4 && c != 4) || ((b == 4 && a != 4 && c != 4) || (c == 4 && a != 4 && b != 4)))
		{
			sTypes.win = sTypes.bet + sTypes.bet;
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
		else if((a == 4 && b == 4 && c != 4) || ((a == 4 && c == 4 && b != 4) || (b == 4 && c == 4 && a != 4)))
		{
			sTypes.win = (sTypes.bet + (sTypes.bet*2));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
		else if(a == 4 && b == 4 && c == 4)
		{
			sTypes.win = (sTypes.bet + (sTypes.bet*12));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::singleDice_5(int a,int b ,int c)
{
	//Button type 49
	if(sTypes.buttonType == 49)
	{
		if((a == 5 && b != 5 && c != 5) || ((b == 5 && a != 5 && c != 5) || (c == 5 && a != 5 && b != 5)))
		{
			sTypes.win = sTypes.bet + sTypes.bet;
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
		else if((a == 5 && b == 5 && c != 5) || ((a == 5 && c == 5 && b != 5) || (b == 5 && c == 5 && a != 5)))
		{
			sTypes.win = (sTypes.bet + (sTypes.bet*2));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
		else if(a == 5 && b == 5 && c == 5)
		{
			sTypes.win = (sTypes.bet + (sTypes.bet*12));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::singleDice_6(int a,int b ,int c)
{
	//Button type 50
	if(sTypes.buttonType == 50)
	{
		if((a == 6 && b != 6 && c != 6) || ((b == 6 && a != 6 && c != 6) || (c == 6 && a != 6 && b != 6)))
		{
			sTypes.win = sTypes.bet + sTypes.bet;
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
		else if((a == 6 && b == 6 && c != 6) || ((a == 6 && c == 6 && b != 6) || (b == 6 && c == 6 && a != 6)))
		{
			sTypes.win = (sTypes.bet + (sTypes.bet*2));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
		else if(a == 6 && b == 6 && c == 6)
		{
			sTypes.win = (sTypes.bet + (sTypes.bet*12));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}

void Button::specStraight_1_2_3(int a,int b ,int c)
{
	//Button type 51
	if(sTypes.buttonType == 52)
	{
		if ((((a == 1 && b == 2 && c == 3) || (a == 1 && b == 3 && c == 2))  ||
			((a == 2 && b == 1 && c == 3)  || (a == 2 && b == 3 && c == 1))) ||
			((a == 3 && b == 1 && c == 2)  || (a == 3 && b == 2 && c == 1)))
		{
			sTypes.win = (sTypes.bet + (sTypes.bet * 30));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::specStraight_2_3_4(int a,int b ,int c)
{
	//Button type 52
	if(sTypes.buttonType == 53)
	{
		if ((((a == 2 && b == 3 && c == 4) || (a == 2 && b == 4 && c == 3))  ||
			((a == 3 && b == 2 && c == 4)  || (a == 3 && b == 4 && c == 2))) ||
			((a == 4 && b == 2 && c == 3)  || (a == 4 && b == 3 && c == 2)))
		{
			sTypes.win = (sTypes.bet + (sTypes.bet * 30));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::specStraight_3_4_5(int a,int b ,int c)
{
	//Button type 53
	if(sTypes.buttonType == 54)
	{
		if ((((a == 3 && b == 4 && c == 5) || (a == 3 && b == 5 && c == 4))  ||
			((a == 4 && b == 3 && c == 5)  || (a == 4 && b == 5 && c == 3))) ||
			((a == 5 && b == 3 && c == 4)  || (a == 5 && b == 4 && c == 3)))
		{
			sTypes.win = (sTypes.bet + (sTypes.bet * 30));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::specStraight_4_5_6(int a,int b ,int c)
{
	//Button type 54
	if(sTypes.buttonType == 55)
	{
		if ((((a == 4 && b == 5 && c == 6) || (a == 4 && b == 6 && c == 5))  ||
			((a == 5 && b == 4 && c == 6)  || (a == 5 && b == 6 && c == 4))) ||
			((a == 6 && b == 4 && c == 5)  || (a == 6 && b == 5 && c == 4)))
		{
			sTypes.win = (sTypes.bet + (sTypes.bet * 30));
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::anyStraight(int a,int b ,int c)
{
	//Button type 55
	vector<int> num;
	num.push_back(a);
	num.push_back(b);
	num.push_back(c);
	sort(num.begin(),num.end());
	if(sTypes.buttonType == 51)
	{
		if(((num[0] + 1) == num[1]) && ((num[1] + 1) == num[2]))
		{
			sTypes.win = sTypes.bet + (sTypes.bet*8);
			SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_ADD);
		}
	}
}
void Button::clearButtons()
{
	SDL_SetSurfaceBlendMode(buttonImage,SDL_BLENDMODE_NONE);
}




