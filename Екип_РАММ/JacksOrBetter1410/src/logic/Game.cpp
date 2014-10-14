/*
 * Game.cpp
 *
 *  Created on: Sep 16, 2014
 *      Author: Keen
 */

#include "Game.h"
using namespace std;

Game::Game()
{
	deck.shuffle();
}

void Game::deal()
{
	for(int hnd=0; hnd<5; hnd++)
	{
		hand.push_back(deck.getCard());
		hold.push_back(true);
	}



	//for(int i=0; i<5; i++)
	//	cout<<hand[i].getImagePath()<<" : "<<hold[i]<<endl;
}

int Game::draw()
{
	for(int hnd=0; hnd<5; hnd++)
		if(!hold[hnd])
			hand[hnd] = deck.getCard();
	//for(int i=0; i<5; i++)
		//cout<<hand[i].getImagePath()<<endl;
return 5;
}

void Game::print()
{
	//for(int i=0; i<5; i++)
		//cout<<hand[i].getImagePath()<<" : "<<hold[i]<<endl;
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}
