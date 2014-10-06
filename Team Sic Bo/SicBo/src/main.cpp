//============================================================================
// Name        : SDL_CODE_FORMATING.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Game.h"
using namespace std;

int main(int argc, char* argv[])
{
	Game sicBo;
	sicBo.init("CODE_FORMATING",70,40,1024,650);
	while(sicBo.isRunning())
	{
		sicBo.handleGameEvents();
	}
	return 0;

}



