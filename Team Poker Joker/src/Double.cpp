#include "Double.h"

Double::Double()
{
	suit = 0;
	face = 0;
}
void Double::drawDoubleCard(SDL_Renderer * gRenderer, int checkSuit,
		Statistics &stat, Credits &credit, Game &game, bool &win)
{
	int x;
	int y;
	setFace();
	setSuit();
	x = getFace() * 79;
	y = getSuit() * 123;

	doubleButton.drawCard(gRenderer, x, y, 144, 55, 150);
	stat.readFromFile();
	stat.addHandsPlayed();
	credit.readCreaditsFromFile(credit);
	switch (checkSuit)
	{
	case -1:
		stat.addWinGames();
		stat.addCreditsWon(bet.wins(game.getWinType()));
		credit.addCredits(bet.wins(game.getWinType()));
		break;
	case 1:
		if ((getSuit() == 1) || (getSuit() == 2)) // pressed RED
		{
			stat.addWinGames();
			stat.addCreditsWon(2 * (bet.wins(game.getWinType())));
			credit.addCredits(2 * (bet.wins(game.getWinType())));
			win = true;
		}
		else
		{
			stat.addLostGames();
			win = false;
		}
		break;
	case 2:
		if ((getSuit() == 0) || (getSuit() == 3)) // pressed BLACK
		{
			stat.addWinGames();
			stat.addCreditsWon(2 * (bet.wins(game.getWinType())));
			credit.addCredits(2 * (bet.wins(game.getWinType())));
			win = true;
		}
		else
		{
			stat.addLostGames();
			win = false;
		}
		break;
	default:
		break;
	}
	stat.writeToFile();
	credit.writeCreditsToFile(credit);

}
void Double::drawDoubleButton(SDL_Renderer * gRenderer, int x, int y, int w,
		int h)
{
	doubleButton.drawButton(gRenderer, x, y, w, h);
}
bool Double::loadDoubleFromFile(SDL_Renderer * gRenderer, string path)
{
	return doubleButton.loadFromFile(gRenderer, path);
}
bool Double::checkDoubleButton(int mouseX, int mouseY)
{
	return doubleButton.checkButton(mouseX, mouseY);
}
int Double::getFace() const
{
	return face;
}

void Double::setFace()
{
	srand(time(0));
	this->face = rand() % 13;
}

int Double::getSuit() const
{
	return suit;
}

void Double::setSuit()
{
	srand(time(0));
	this->suit = rand() % 4;
}
