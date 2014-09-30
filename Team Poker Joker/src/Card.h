/*
 * Card.h
 *
 *  Created on: 17.09.2014 г.
 *      Author: Kateto
 */

#ifndef CARD_H_
#define CARD_H_

class Card
{
	friend class Game;
private:
	static const char *faces[];
	static const char *suits[];

	int suit;
	int face;

	bool m_bIsHold;
public:

	Card();
	Card(int suit, int face);


	void Hold()
	{
		m_bIsHold = true;
	}
	void Unhold()
	{
		m_bIsHold = false;
	}

	bool isHold()
	{
		return m_bIsHold;
	}

	int getFace() const;
	void setFace(int face);

	int getSuit() const;
	void setSuit(int suit);

};

#endif /* CARD_H_ */
