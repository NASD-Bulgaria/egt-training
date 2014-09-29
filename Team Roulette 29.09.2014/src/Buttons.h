#ifndef BUTTONS_H_
#define BUTTONS_H_

#include <string>
#include "LTexture.h"

using namespace std;

class Buttons : public LTexture
{
public:
	Buttons( string = "", int = 0, int = 0, int = 0, int = 0 );
	~Buttons();
	void setButtonName( string buttonName );
	bool clicked ( int mouseX, int mouseY );

private:
char buttonName[15];

};
#endif 
