#include "Buttons.h"
#include <iostream>

Buttons::Buttons(string buttonName, int x, int y, int mWidth, int mHeight) : LTexture(x, y, mWidth, mHeight)
{
setButtonName(buttonName);
}

Buttons::~Buttons()
{

}

void Buttons::setButtonName( string buttonName )
{
int length = buttonName.size();

   length = ( length < 15 ? length : 14 );

   buttonName.copy( this->buttonName, length );

   this->buttonName[length] = '\0';
}

bool Buttons::clicked ( int mouseX, int mouseY )
{
	if (mouseX >= this->x && mouseX <= this->x + this->mWidth && mouseY >= this->y && mouseY <= this->y + this->mHeight)
	{
		return true;
	}

	return false;
}
