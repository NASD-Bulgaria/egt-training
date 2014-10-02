#ifndef STATISTICS_H_
#define STATISTICS_H_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "EnumTypes.h"
#include "IRendable.h"
#include <sstream>
#include <iomanip>
using namespace GameObjects;
using namespace std;

class Statistics : public IRendable
{
public:
	Statistics(string path = "", int initialAmount = 0);
	bool write(short num, Color color, int totalBet, int winings, int currentBalance);
	void read(SDL_Renderer* gRenderer);
	virtual ~Statistics();
	virtual void draw(SDL_Renderer*, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	virtual void free();
private:
	string path;
	const int initialAmount;
	fstream stream;
	vector<SDL_Texture*> textTextures;
	bool initiateStream();
	string colors[3];
	double calcDeviateBet(int totalBet, int winings);
	double calcDeviateCapital(int currentBalance);
	void destroyTextures();
};

#endif /* STATISTICS_H_ */
