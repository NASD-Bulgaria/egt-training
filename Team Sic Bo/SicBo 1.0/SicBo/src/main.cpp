//============================================================================
// Name        : SDL_CODE_FORMATING.cpp
// Author      : 
// Version     :
// Copyright   : You r copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Start.h"
using namespace std;

int main(int argc, char* argv[])
{
	Start sicBo;
	sicBo.init("Sic Bo v1.0b",70,40,1024,701);
	while(sicBo.isRunning())
	{
		sicBo.startMenu();
	}

	return 0;
}



