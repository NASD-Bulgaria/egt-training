/*
 * BingoTicket.cpp
 *
 *  Created on: 18.09.2014
 *      Author:
 */

#include "BingoTicket.h"

BingoTicket::BingoTicket()
{
	drawNewTicket();
}

BingoTicket::~BingoTicket()
{
}

void BingoTicket::clearTicket(vector<int> &tmp)
{
	while(!tmp.empty())
	{
		tmp.pop_back();
	}
}

void BingoTicket::drawNewTicket() // generates new ticket
{
	// Clears every vector to fill again without repeating any number
	clearTicket(b);
	clearTicket(i);
	clearTicket(n);
	clearTicket(g);
	clearTicket(o);

	// Fills every column with numbers
	for(int q = 1; q < 16; q++)
		{
			b.push_back(q);
			i.push_back(q + 15);
			n.push_back(q + 30);
			g.push_back(q + 45);
			o.push_back(q + 60);
		}

		// shuffles every column
		random_shuffle(b.begin(), b.end());
		random_shuffle(i.begin(), i.end());
		random_shuffle(n.begin(), n.end());
		random_shuffle(g.begin(), g.end());
		random_shuffle(o.begin(), o.end());

		// convert integer numbers to strings
		for(int row = 0; row < 5; row++)
		{
				fill(b.back(), row, 0); // fills 1st(B) column with 5 random numbers
				b.pop_back();

				fill(i.back(), row, 1); // fills 2nd(I) column with 5 random numbers
				i.pop_back();

				fill(n.back(), row, 2); // fills 3rd(N) column with 4(x2 ,y2 is a free slot) random numbers
				n.pop_back();

				fill(g.back(), row, 3); // fills 4th(G) column with 5 random numbers
				g.pop_back();

				fill(o.back(), row, 4); // fills 5th(O) column with 5 random numbers
				o.pop_back();
		}
		ticket[2][2] = "X"; // free space in the middle of the ticket
}

void BingoTicket::fill(int temp, int row, int col)
{
	stringstream convert;
	convert << temp;
	ticket[row][col] =	convert.str();
}

void BingoTicket::putOnScreen(int xPos, int yPos)
{
	int tmp = xPos;
	SDL_Color color = {0, 0, 0};
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			ticket1Nums.loadFromRenderedText(ticket[i][j].c_str(), color);
			if(ticket[i][j].length() == 1)
			{
				if(ticket[i][j] == "X")
				{
					gMark.render(xPos - 5, yPos - 5);
				}
				int tmp = xPos + 8;
				ticket1Nums.render(tmp+3, yPos+1);
			}
			else
			{
				ticket1Nums.render(xPos, yPos);
			}

			xPos += 50;
		}
		xPos = tmp;
		yPos += 50;
	}
}
